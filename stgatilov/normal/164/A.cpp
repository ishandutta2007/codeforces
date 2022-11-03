#pragma comment(linker, "/STACK:10000000")
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

const int SIZE = 1<<17;

int n, m;
char oper[SIZE];
vector<int> nbr[SIZE], anti[SIZE];

bool fromdef[SIZE];
bool touse[SIZE];

bool used[SIZE];

void DFS1(int u) {
	fromdef[u] = true;
	used[u] = true;
	for (int i = 0; i<nbr[u].size(); i++) {
		int v = nbr[u][i];
		if (used[v]) continue;
		DFS1(v);
	}
}

void DFS2(int u) {
	touse[u] = true;
	used[u] = true;
	if (oper[u] == 1) return;
	for (int i = 0; i<anti[u].size(); i++) {
		int v = anti[u][i];
		if (used[v]) continue;
		DFS2(v);
	}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++) {
		int t;
		scanf("%d", &t);
		oper[i] = t;
	}
	for (int i = 0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;  b--;
		nbr[a].push_back(b);
		anti[b].push_back(a);
	}

	memset(used, 0, sizeof(used));
	for (int i = 0; i<n; i++) if (oper[i] == 1)
		if (!used[i])
			DFS1(i);
    
	memset(used, 0, sizeof(used));
	for (int i = 0; i<n; i++) if (oper[i] == 2)
		if (!used[i])
			DFS2(i);

/*	for (int i = 0; i<n; i++) printf("%d ", int(fromdef[i])); printf("\n");
	for (int i = 0; i<n; i++) printf("%d ", int(touse[i])); printf("\n");*/

	for (int i = 0; i<n; i++) printf("%d ", int(fromdef[i] && touse[i])); printf("\n");

	return 0;
}