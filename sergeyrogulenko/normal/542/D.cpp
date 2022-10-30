#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>
#include <unordered_map>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

const int N = 1000 * 1000;

bool prime[N + 1];

bool isPrime(int64 x) {
	if (x == 1) return 0;
	for (int64 i = 2; i * i <= x; i++)
		if (x % i == 0) return 0;
	return 1;
}

int64 maxp;
vector<vector<int64> > pr;
vector< unordered_map<int64, int> > t;
int y = 0;

int go(int64 n, int p) {
	if (n == 1) return 1;
	if (t[p].count(n)) return t[p][n];
	int64 ans = 0;
	if (p == I pr.size()) {
		if (n - 1 > maxp && isPrime(n - 1)) ans++;
		return t[p][n] = ans;
	}
	ans += go(n, p + 1);
	forn(i, pr[p].size()) {
		if (n % pr[p][i] == 0) {
			ans += go(n / pr[p][i], p + 1);
		}
	}
	return t[p][n] = ans;
}

int gcd(int a, int b) {
	return a ? gcd(b % a, a) : b;
}

int sm(int n) {
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (n % i == 0 && gcd(n / i, i) == 1)
			res += i;
	return res;
}

int slow(int n) {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (sm(i) == n) {
			res++;
		}
	}
	return res;
}

int64 fast(int64 n) {
	pr.clear();
	for (int i = 2; i <= N; i++)
		if (prime[i]) {
			int64 j = i;
			vector<int64> q;
			int c = 1;
			while (j + 1 <= n) {
				if (n % (j + 1) == 0) {
					q.pb(j + 1);
					maxp = i;
				}
				j *= (int64)i;
				c++;
			}
			if (q.size() > 0) {
				pr.pb(q);
			}
		}
	t.clear();
	t.resize(pr.size() + 1);
	return go(n, 0);
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	for (int i = 2; i <= N; i++) prime[i] = 1;
	for (int i = 2; i <= N; i++)
		if (prime[i]) {
			int v = i * 2;
			while (v <= N) {
				prime[v] = 0;
				v += i;
			}
		}
	/*
	for (int n = 1; n <= 1000; n++)
		if (fast(n) != slow(n)) {
			cerr << n << " " <<  fast(n) << " " << slow(n) << endl;
		}
	return 0;
	*/
	int64 n;
	cin >> n;
	cout << fast(n) << endl;
//	cerr << clock() << endl;
//	cerr << y << endl;
	return 0;
}