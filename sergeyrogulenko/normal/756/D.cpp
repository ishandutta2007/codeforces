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
#define next NEXT64
#define prev PREV64
#define y1 Y164

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr(T x) { return x * x; }

const int P = 1000000007;

int n;
string s;
int t[5050][5050];
int f[26];
int x[5050];
bool u[26];

inline int mod(int x) {
	if (x >= P) return x - P;
	return x;
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> n >> s;
	forn(i, n) x[i] = s[i] - 'a';
	seta(t, 0);
	for (int j = 0; j < n; j++) {
		int sm = 0;
		if (j == 0) {
			forn (i, n) t[j][i] = 1;
			continue;
		}
		seta(f, 0);
		for (int i = 0; i < n; i++) {
			sm = mod(sm - f[x[i]] + P);
			f[x[i]] = t[j-1][i];
			sm = mod(sm + f[x[i]]);
			t[j][i] = sm;
		}
	}
	int ans = 0;
	seta(u, 0);
	for (int i = n-1; i >= 0; i--) {
		if (!u[x[i]]) {
			ans = mod(ans + t[n-1][i]);
			u[x[i]] = 1;
		} 
	}
	cout << ans << endl;
	return 0;
}