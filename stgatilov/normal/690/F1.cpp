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

const int SIZE = 1<<20;

int n, m;
vector<int> nbr[SIZE];

/*bool used[SIZE];
int dist[SIZE];
void DFS(int u, int d) {
	used[u] = true;
	dist[u] = d;
	for (int i = 0; i < nbr[u].size(); i++) {
		int v = nbr[u][i];
		if (!used[v])
			DFS(v, d+1);
	}
}*/

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	m = n-1;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		nbr[a].push_back(b);
		nbr[b].push_back(a);
	}
	
	int64 ans = 0;
	for (int i = 0; i < n; i++) {
		int64 deg = nbr[i].size();
		if (deg >= 2)
			ans += (deg * (deg-1)) / 2;
	}

	printf("%I64d\n", ans);

	return 0;
}