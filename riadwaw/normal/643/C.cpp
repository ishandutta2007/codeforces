#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <deque>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
//#include <unordered_map>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef room111
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	start = clock();
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	int testNum = 1;
	while (t--) {
		//cerr << testNum << endl;
		//cout << "Case #" << testNum++ << ": ";
		solve();
		++testNumber;
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 300500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

/*int curMod = 1000000009;

int fact[100500], revfact[100500];

int getC(int n, int k) {
int res = fact[n] * revfact[n - k] % curMod * revfact[k] % curMod;
return res;
}*/

/*const int C = 7000500;

int least_prime[C];*/

void precalc() {

	/*for (int i = 2; i < C; ++i) {
	if (!least_prime[i]) {
	least_prime[i] = i;
	for (li j = i * 1LL * i; j < C; j += i) {
	least_prime[j] = i;
	}
	}
	}*/

	/*fact[0] = revfact[0] = 1;
	for (int i = 1; i < 100500; ++i) {
	fact[i] = fact[i - 1] * i % curMod;
	revfact[i] = binpow(fact[i], curMod - 2, curMod);
	}*/

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/
	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/
}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}

//#define int li

//const int mod = 1000000007;

struct Line {
	ld a, b;
	ld border;
};

vector<int> uk;
vector<vector<Line>> lines;

void append(int id, Line new_line) {
	while (!lines[id].empty()) {
		Line last = lines[id].back();
		ld x = (last.a - new_line.a) / (last.b - new_line.b);
		if (x < last.border) {
			lines[id].pop_back();
			if (uk[id] >= lines[id].size() && uk[id] > 0) {
				--uk[id];
			}
		}
		else {
			new_line.border = x;
			break;
		}
	}
	if (lines[id].empty()) {
		new_line.border = 0;
	}
	lines[id].push_back(new_line);
}

ld get_val(const Line& line, ld x) {
	return line.a - line.b * x;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> t(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	vector<vector<ld>> dp(n + 1, vector<ld>(k + 1, 4e18));
	dp[0][0] = 0;

	uk.assign(k + 1, 0);
	lines.resize(k + 1);
	lines[0].push_back({0, 0, 0});

	vector<ld> pref_sum(n + 1);
	for (int i = 0; i < n; ++i) {
		pref_sum[i + 1] = pref_sum[i] + t[i];
	}

	vector<ld> sum_obr(n + 1);
	for (int i = 0; i < n; ++i) {
		sum_obr[i + 1] = sum_obr[i] + 1.0 / t[i];
	}
	vector<ld> sum_vals(n + 1);
	for (int i = 0; i < n; ++i) {
		sum_vals[i + 1] = sum_vals[i] + pref_sum[i + 1] / 1.0 / t[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int used = k - 1; used >= 0; --used) {
			while (uk[used] + 1 < lines[used].size() && get_val(lines[used][uk[used]], sum_obr[i + 1]) > get_val(lines[used][uk[used] + 1], sum_obr[i + 1])) {
				++uk[used];
			}
			if (uk[used] < lines[used].size()) {
				dp[i + 1][used + 1] = sum_vals[i + 1] + get_val(lines[used][uk[used]], sum_obr[i + 1]);
				//cout << i + 1 << ' ' << used + 1 << ' ' << dp[i + 1][used + 1] << "\n";
				append(used + 1, { dp[i + 1][used + 1] - sum_vals[i + 1] + sum_obr[i + 1] * pref_sum[i + 1], pref_sum[i + 1], 4e18 });
			}
		}
	}

	cout << dp[n][k] << "\n";

}