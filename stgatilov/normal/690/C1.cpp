//#pragma comment(linker, "/STACK:20000000")
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

const int SIZE = 1024;

int n, m;
vector<int> nbr[SIZE];

bool used[SIZE];
void DFS(int u) {
	used[u] = true;
	for (int i = 0; i < nbr[u].size(); i++) {
		int v = nbr[u][i];
		if (!used[v])
			DFS(v);
	}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		nbr[a].push_back(b);
		nbr[b].push_back(a);
	}

	if (m != n-1)
		printf("no");
	else {
		DFS(0);
		int visCnt = 0;
		for (int i = 0; i < n; i++) visCnt += !!used[i];
		printf(visCnt == n ? "yes" : "no");
	}

	return 0;
}