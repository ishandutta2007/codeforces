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

const int SIZE = 1<<16;
const int DIST = 1<<9;

int n, k;
vector<int> nbr[SIZE];
int pcnt[SIZE][DIST];
int64 pairs[SIZE], redpairs[SIZE];

int64 ans;
bool vis[SIZE];
void DFS(int u) {
	vis[u] = true;

	int64 tres = 0;
	
	for (int i = 0; i<nbr[u].size(); i++) {
		int v = nbr[u][i];
		if (vis[v]) continue;
		DFS(v);

		for (int d = 0; d<k; d++)
			pcnt[u][d+1] += pcnt[v][d];
		tres -= redpairs[v];
	}

	pcnt[u][0]++;

	for (int d = 0; d<=k; d++)
		pairs[u] += int64(pcnt[u][d]) * pcnt[u][k-d];
	for (int d = 0; d<=k-2; d++)
		redpairs[u] += int64(pcnt[u][d]) * pcnt[u][k-2-d];

	tres += pairs[u];
	ans += tres;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &k);
	for (int i = 0; i<n-1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;  b--;
		nbr[a].push_back(b);
		nbr[b].push_back(a);
	}

	if (k == 1) {
		printf("%d\n", n-1);
		return 0;
	}

	DFS(0);

	assert(ans % 2 == 0);
	printf("%I64d\n", ans / 2);

	return 0;
}