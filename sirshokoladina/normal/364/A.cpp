#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <algorithm>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

int s[5000];
ll k[50000];

int main () {
#ifndef SUKPZDC
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#else
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int a;
	cin >> a;
	string t;
	getline(cin, t);
	getline(cin, t);
	s[0] = 0;
	forn (i, t.size()) {
		s[i + 1] = s[i] + t[i] - '0';
	}
	forn (i, t.size() + 1) {
		forn (j, i) {
			k[s[i] - s[j]]++;
		}
	}
	if (a == 0) {
		cout << k[0] * t.size() * (t.size() + 1) - k[0] * k[0] << endl;
		return 0;
	}
	ll ans = 0;
	for (int i = 1; i < 50000; ++i) {
		if (a % i == 0 && a / i < 50000) {
			ans += k[i] * k[a / i];
		}
	}
	cout << ans << endl;
	return 0;
}