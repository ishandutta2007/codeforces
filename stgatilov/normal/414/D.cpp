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

int n, k, p;
vector<int> nbr[SIZE];

int m;
int arr[SIZE];
int psum[SIZE];
int64 qsum[SIZE];

bool used[SIZE];
void DFS(int u, int h) {
	m = max(m, h);
	if (h > 0)
		arr[h-1]++;

	used[u] = true;
	for (int i = 0; i<nbr[u].size(); i++) {
		int v = nbr[u][i];
		if (used[v]) continue;
		DFS(v, h+1);
	}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 0; i<n-1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;  b--;
		nbr[a].push_back(b);
		nbr[b].push_back(a);
	}

	DFS(0, 0);

	psum[0] = 0;
	for (int i = 0; i<m; i++) psum[i+1] = psum[i] + arr[i];

	qsum[0] = 0;
	for (int i = 0; i<m; i++) qsum[i+1] = qsum[i] + arr[i] * int64(i);

/*	for (int i = 0; i<m; i++) Ef("%d ", arr[i]); Ef("\n");
	for (int i = 0; i<=m; i++) Ef("%d ", psum[i]); Ef("\n");
	for (int i = 0; i<=m; i++) Ef("%d ", qsum[i]); Ef("\n");*/

	int ans = 0;
	for (int r = 0; r<m; r++) {
		int left = 0;
		int right = min(psum[r+1], k) + 1;

		while (right - left > 1) {
			int middle = (left + right) / 2;

			int rem = psum[r+1] - middle;
			auto it = lower_bound(psum, psum+m+1, rem);
			int l = (it - psum) - 1;
			int tail = psum[l+1] - rem;

			int64 full = int64(r) * (psum[r+1] - psum[l+1]) - (qsum[r+1] - qsum[l+1]);
			int64 tlcost = int64(tail) * (r - l);
			int64 total = full + tlcost;

/*			Eo(middle);
			Eo(rem);
			Eo(l);
			Eo(r);
			Eo(tail);
			Eo(full);
			Eo(tlcost);
			Eo(total);
			E(\n);*/

			if (total <= p)
				left = middle;
			else
				right = middle;
		}

		ans = max(ans, left);
	}

	printf("%d\n", ans);

	return 0;
}