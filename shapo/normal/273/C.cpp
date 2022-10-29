#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <string>

using namespace std;

#ifdef WIN32
	#define LLD "%I64d"
	#define LLU "%I64u"
#else
	#define LLD "%lld"
	#define LLU "%llu"
#endif

#define pb push_back
#define mp make_pair
#define fill(a,x) memset(a,x,sizeof(a))
#define sz(a) (int)(a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;

#define maxn 300500

int n, m;
vi edge[maxn], con[maxn];
int col[maxn];
int used[maxn];
int tin[maxn];
int ctimer = 0;
set < int > deg[4];
int curl[maxn];

int DFS(int x) {
	tin[x] = ++ctimer;
	used[x] = true;
	int nm[2] = {};
	for (int i = 0; i < sz(edge[x]); ++i) {
		if (!used[edge[x][i]])
			DFS(edge[x][i]);
		++nm[col[edge[x][i]]];
	}
	if (nm[0] > 1)
		col[x] = 1;
	else
		col[x] = 0;
	return col[x];
}

int change(int pos) {
	int togo = *(deg[pos].begin());
	col[togo] ^= 1;
	deg[pos].erase(togo);
	int cnt = 0;
	for (int i = 0; i < sz(edge[togo]); ++i)
		if (col[edge[togo][i]] == col[togo]) ++cnt;
	deg[cnt].insert(togo);
	curl[togo] = cnt;
	for (int i = 0; i < sz(edge[togo]); ++i) {
		int go = edge[togo][i];
		deg[curl[go]].erase(go), cnt = 0;
		for (int j = 0; j < sz(edge[go]); ++j)
			if (col[edge[go][j]] == col[go]) ++cnt;
		curl[go] = cnt;
		deg[curl[go]].insert(go);
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	for (int i = 1; i <= n; ++i)
		deg[sz(edge[i])].insert(i), col[i] = 0, curl[i] = sz(edge[i]);
	while (!deg[2].empty() || !deg[3].empty()) {
		if (!deg[3].empty()) {
			change(3);
		} else {
			change(2);
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d", col[i]);
	printf("\n");
	return 0;
}