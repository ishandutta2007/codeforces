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

int n, s;
int magic;
struct Elem {
	int val;
	int cnt;
	inline bool operator< (const Elem &x) const { return val < x.val; }
};
int arr[32];
int g;
Elem groups[32];

int csum;
vector<int> poss[5];
void RecPoss(int k, int u) {
	poss[k].push_back(csum);
	if (k == n) return;
	for (int i = u; i<s; i++) {
		csum += arr[i];
		RecPoss(k+1, i+1);
		csum -= arr[i];
	}
}

inline bool ContPossible(int hascnt, int currsum) {
	int remcnt = n-1-hascnt;
	return binary_search(poss[remcnt].begin(), poss[remcnt].end(), magic - currsum);
}


int matr[8][8];
int rowsum[8], colsum[8], diagsum[2];
void Solve(int u, int v) {
	if (u == n) {

		if (diagsum[0] != magic || diagsum[1] != magic) return;
		for (int i = 0; i<n; i++) {
			if (rowsum[i] != magic) return;
			if (colsum[i] != magic) return;
		}

		printf("%d\n", magic);
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++)
				printf("%d ", matr[i][j]);
			printf("\n");
		}
		exit(0);
	}

	if (v == n) {
		if (rowsum[u] == magic)
			Solve(u+1, 0);
		return;
	}

	for (int i = 0; i<g; i++) if (groups[i].cnt) {
		int x = groups[i].val;

		groups[i].cnt--;
		matr[u][v] = x;

		rowsum[u] += x;
		colsum[v] += x;
		bool diagok = true;
		if (u==v) {
			diagsum[0] += x;
			diagok &= ContPossible(u, diagsum[0]);
		}
		if (u+v==n-1) {
			diagsum[1] += x;
			diagok &= ContPossible(u, diagsum[1]);
		}

		if (diagok && /*ContPossible(v, rowsum[u]) &&*/ ContPossible(u, colsum[v]))
			Solve(u, v+1);

		groups[i].cnt++;
		matr[u][v] = 0;

		rowsum[u] -= x;
		colsum[v] -= x;
		if (u==v) diagsum[0] -= x;
		if (u+v==n-1) diagsum[1] -= x;
	}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	s = n*n;
	for (int i = 0; i<s; i++) scanf("%d", &arr[i]);

	int sum = 0;
	for (int i = 0; i<s; i++) sum += arr[i];
	magic = sum / n;

	sort(arr, arr+s);
	arr[s] = 1000000000;
	int tcnt = 0;
	for (int i = 0; i<s; i++) {
		tcnt++;
		if (arr[i+1] != arr[i]) {
			groups[g].val = arr[i];
			groups[g].cnt = tcnt;
			g++;
			tcnt = 0;
		}
	}
	random_shuffle(groups, groups+g);

	RecPoss(0, 0);
	for (int i = 0; i<=n; i++) {
		std::sort(poss[i].begin(), poss[i].end());
		poss[i].resize(std::unique(poss[i].begin(), poss[i].end()) - poss[i].begin());
	}

	Solve(0, 0);

	return 0;
}