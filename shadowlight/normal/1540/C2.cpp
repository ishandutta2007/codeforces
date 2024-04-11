#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
 
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif
 
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
 
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
 
 
const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}
 
 
const int N = 102;
const int C = 10101;
int n;
int c[N];
int b[N];
int sumB[N];
int dp[2][N][C];
int ANS[N];
int m;
 
int getAvg(int x, int y) {
	if (x >= 0) return x / y;
	return (x - y + 1) / y;
}
 
int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
 
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i < n; i++) {
		int x;
		scanf("%d", &x);
		b[i] = b[i - 1] - x;
		sumB[i] = sumB[i - 1] + b[i];
	}
	m = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += b[i];
		m = min(m, getAvg(sum, i + 1));
	}
	//eprintf("m = %d\n", m);
	dp[0][N - 1][0] = 1;
	for (int it = 0; it < n; it++) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < C; j++)
				dp[1][i][j] = 0;
		for (int avg = 0; avg < N; avg++)
			for (int sm = 0; sm < C; sm++) {
				if (dp[0][avg][sm] == 0) continue;
				int w = dp[0][avg][sm];
				int r = c[it];
				int curSum = sm + sumB[it];
				while(r >= 0) {
					int curAvg = getAvg(curSum + r, it + 1);
					assert(curAvg >= m);
					curAvg = min(avg, curAvg - m);
					int l = (m + curAvg) * (it + 1) - curSum;
					l = max(l, 0);
					assert(l <= r);
					dp[1][curAvg][sm + l] = add(dp[1][curAvg][sm + l], w);
					dp[1][curAvg][sm + r + 1] = sub(dp[1][curAvg][sm + r + 1], w);
					r = l - 1;
				}
			}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < C; j++) {
				if (j == 0)
					dp[0][i][j] = 0;
				else
					dp[0][i][j] = dp[0][i][j - 1];
				dp[0][i][j] = add(dp[0][i][j], dp[1][i][j]);
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < C; j++)
			ANS[i] = add(ANS[i], dp[0][i][j]);
	for (int i = N - 2; i >= 0; i--)
		ANS[i] = add(ANS[i], ANS[i + 1]);
	int q;
	scanf("%d", &q);
	while(q--) {
		int x;
		scanf("%d", &x);
		x = min(x, m + N - 1);
		x = max(x, m);
		printf("%d\n", ANS[x - m]);
	}
 
	return 0;
}