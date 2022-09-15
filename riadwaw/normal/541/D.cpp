#pragma comment (linker, "/STACK:128000000")
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
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
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

bool doing = true;

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
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
	int testNum = 1;
	while (t--) {
		//cout << "Case #" << testNum++ << ": ";
		solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

#define int li

const int C = 1000500;

int notPrime[C];

vector<int> primes;

void precalc() {
	notPrime[0] = true;
	notPrime[1] = true;
	for (int i = 2; i < C; ++i) {
		if (notPrime[i]) {
			continue;
		}
		primes.push_back(i);
		for (int j = i * i; j < C; j += i) {
			notPrime[j] = true;
		}
	}
}

bool isPrime(int cur) {
	if (cur < C) {
		return !notPrime[cur];
	}
	for (int p : primes) {
		if (p * p > cur)
			break;
		if (cur % p == 0) {
			return false;
		}
	}
	return true;
}

vector<int> dels;
vector<vector<pair<pair<int, int>, int>>> powers;

map<pair<int, int>, int> dp;

int rec(int A, int pos) {
	auto it = dp.find(mp(A, pos));
	if (it != dp.end()) {
		return it->second;
	}
	if (A == 1) {
		return dp[mp(A, pos)] = 1;
	}

	int delId = lower_bound(all(dels), A) - dels.begin();

	int nextPos = lower_bound(all(powers[delId]), mp(mp(pos, 0LL), 0LL)) - powers[delId].begin();
	if (nextPos == powers[delId].size()) {
		return dp[mp(A, pos)] = 0;
	}

	if (powers[delId][nextPos].first.first > pos) {
		return rec(A, powers[delId][nextPos].first.first);
	}

	int res = 0;
	for (int i = nextPos; i < powers[delId].size() && powers[delId][i].first.first == pos; ++i) {
		res += rec(A / powers[delId][i].second, pos + 1);
	}
	res += rec(A, pos + 1);

	return dp[mp(A, pos)] = res;
}

void solve() {
	int A;
	cin >> A;
	for (int i = 1; i * i <= A; ++i) {
		if (A % i) {
			continue;
		}
		dels.push_back(i);
		if (i * i != A) {
			dels.push_back(A / i);
		}
	}
	sort(all(dels));

	powers.resize(dels.size());

	int oldPrimes = primes.size();

	for (int i = 0; i < dels.size(); ++i) {
		int d = dels[i];
		if (isPrime(d - 1) && d - 1 >= C) {
			primes.push_back(d - 1);
		}
	}

	sort(all(primes));
	primes.erase(unique(all(primes)), primes.end());


	for (int i = 0; i < dels.size(); ++i) {
		int d = dels[i];
		if (isPrime(d - 1)) {
			powers[i].push_back(mp(mp(lower_bound(all(primes), d - 1) - primes.begin(), 1), d));
		}
		for (int j = 0; j < oldPrimes; ++j) {
			int p = primes[j];
			if (p * p > d) {
				break;
			}
			
			int cur = p;
			int cnt = 1;
			while (cur + 1 <= d) {
				if (d % (cur + 1) == 0) {
					powers[i].push_back(mp(mp(j, cnt), cur + 1));
				}
				++cnt;
				cur *= p;
			}
		}
	}

	for (int i = 0; i < dels.size(); ++i) {
		sort(all(powers[i]));
	}

	cout << rec(A, 0) << "\n";

}