#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 100<<10;
const int LOGS = 17;

int n, m, k;
vector<int> nbr[SIZE];
vector<int> dir[SIZE];

int order[SIZE], ordk;
bool used[SIZE];
void DFS1(int u, int f) {
	used[u] = true;
	for (int i = 0; i<nbr[u].size(); i++) {
		int v = nbr[u][i];
		if (v == f) continue;

		dir[v].push_back(u);
//		dir[u].push_back(v);
		if (!used[v])
			DFS1(v, u);
	}
	order[ordk++] = u;
}

int comps;
int color[SIZE];
void DFS2(int u) {
	used[u] = true;
	color[u] = comps;
	for (int i = 0; i<dir[u].size(); i++) {
		int v = dir[u][i];
		if (!used[v])
			DFS2(v);
	}
}

int t;
vector<int> trn[SIZE];
int trhgt[SIZE];
int trfth[LOGS+1][SIZE];
void DFS3(int u, int h, int f) {
	used[u] = true;
	trfth[0][u] = f;
	trhgt[u] = h;
	for (int i = 0; i<trn[u].size(); i++) {
		int v = trn[u][i];
		if (!used[v])
			DFS3(v, h+1, u);
	}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;  b--;
		nbr[a].push_back(b);
		nbr[b].push_back(a);
	}

	DFS1(0, -1);
	reverse(order, order+n);

//	for (int i = 0; i<n; i++) Ef("%d ", order[i]); E(\n);

	memset(used, 0, sizeof(used));
	for (int i = 0; i<n; i++) if (!used[order[i]]) {
		DFS2(order[i]);
		comps++;
	}

//	for (int i = 0; i<n; i++) Ef("%d ", color[i]); E(\n);

	t = comps;
	for (int u = 0; u<n; u++)
		for (int j = 0; j<nbr[u].size(); j++) {
			int v = nbr[u][j];
			if (color[u] == color[v]) continue;

			trn[color[u]].push_back(color[v]);
			trn[color[v]].push_back(color[u]);
		}

	memset(used, 0, sizeof(used));
	DFS3(0, 0, -1);

	for (int l = 0; l<LOGS; l++) {
		for (int i = 0; i<t; i++) {
			int q = trfth[l][i];
			if (q >= 0) q = trfth[l][q];
			trfth[l+1][i] = q;
		}
	}

	scanf("%d", &k);
	for (int i = 0; i<k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;  b--;
		int ca = color[a];
		int cb = color[b];
		if (trhgt[ca] < trhgt[cb]) swap(ca, cb);
		
		int va = ca, vb = cb;
		for (int l = LOGS; l>=0; l--)
			if (trhgt[va] - (1<<l) >= trhgt[vb])
				va = trfth[l][va];
		assert(trhgt[va] == trhgt[vb]);

		for (int l = LOGS; l>=0; l--)
			if (trfth[l][va] != trfth[l][vb]) {
				va = trfth[l][va];
				vb = trfth[l][vb];
			}
		if (va != vb) {
			va = trfth[0][va];
			vb = trfth[0][vb];
		}
		assert(va == vb);

		int ans = trhgt[ca] + trhgt[cb] - 2*trhgt[va];
		printf("%d\n", ans);
	}

	return 0;
}