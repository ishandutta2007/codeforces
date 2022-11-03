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

const int MOD = 1000000007;

int n, m, k;
int matr[16][16];
int src[16][16];

int comb(int n, int k) {
	if (k < 0 || k > n) return 0;
	int res = 1;
	for (int i = n; i>n-k; i--)
		res *= i;
	return res;
}

int64 ans;
int colus;
int corr[16];
void Solve(int u, int v) {
	if (u == n) {
		bool tmp[16] = {false};
		int fk = 0;
		for (int i = 0; i<colus; i++) {
			if (corr[i] < 0) fk++;
			else {
				if (tmp[corr[i]]) return;
				tmp[corr[i]] = true;
			}
		}

		ans += comb(k-(colus-fk), fk);
		return;
	}
	if (v == m) return Solve(u+1, 0);

	bool used[16] = {false};
	matr[u][v] = k;
	for (int i = 0; i<=u; i++)
		for (int j = 0; j<=v; j++)
			used[matr[i][j]] = true;
	matr[u][v] = -1;

	int remk = (n-u) + (m-v) - 1;
	int freek = 0;
	for (int t = 0; t<k; t++) freek += !used[t];
	if (remk > freek) return;

	for (int t = 0; t<min(k, colus+1); t++) if (!used[t]) {
		bool newc = (t == colus);
		bool setc = false;

		if (src[u][v] >= 0) {
			if (corr[t] >= 0) {
				if (corr[t] != src[u][v]) continue;
			}
			else setc = true;
		}

		if (setc) corr[t] = src[u][v];
		colus += newc;
		matr[u][v] = t;
		Solve(u, v+1);
		matr[u][v] = -1;
		colus -= newc;
		if (setc) corr[t] = -1;
	}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d%d", &n, &m, &k);
	if (n+m-1 > k) {
		printf("%d\n", 0);
		return 0;
	}
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++) {
			scanf("%d", &src[i][j]);
			src[i][j]--;
		}

	memset(corr, -1, sizeof(corr));
	memset(matr, -1, sizeof(matr));
	Solve(0, 0);

//	printf("%I64d\n", ans);
	printf("%I64d\n", ans % MOD);

	return 0;
}