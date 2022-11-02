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

int n;
int s[1<<20][21];
int power[1<<20];
int sum[1<<20];

const int MOD = 1000000007;

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	seta(s, 0);
	scanf("%d", &n);
	//n = 1000001;
	forn(i, n) {
		int x;
		//x = i;
		scanf("%d", &x);
		s[x][20]++;
	}
	power[0] = 1;
	for (int i = 1; i < (1<<20); i++) {
		power[i] = power[i-1] * 2;
		if (power[i] >= MOD)
			power[i] -= MOD;
	}
	sum[0] = 0;
	forn(i, 1 << 20)
		sum[i] = sum[i/2] + (i & 1);
	ford(mask, 1 << 20) {
		ford(i, 21) {
			if (i > 0) {
				s[mask][i-1] += s[mask][i];
				if (mask & (1 << (i-1))) {
					s[mask^(1<<(i-1))][i-1] += s[mask][i];
				}
			}
		}
	}
	int64 ans = power[n] - 1;
	ans = (ans + MOD) % MOD;
	forn(mask, 1 << 20)
		if (mask) {
			int64 cnt = (power[s[mask][0]] - 1 + MOD) % MOD;
			if (sum[mask] & 1)
				ans = (ans - cnt + MOD) % MOD;
			else
				ans = (ans + cnt) % MOD;
		}
	cout << ans << endl;
	return 0;
}