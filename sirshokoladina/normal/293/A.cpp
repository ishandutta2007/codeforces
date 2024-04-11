#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld pi = 3.141592653589793238462643l;

int main () {
#ifdef LOCAL
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n;
	cin >> n;
	string s, t;
	getline(cin, s);
	getline(cin, s);
	getline(cin, t);
	int a00 = 0, a01 = 0, a10 = 0, a11 = 0;
	forn (i, 2 * n) {
		if (s[i] == '0' && t[i] == '0') {
			a00++;
		}
		if (s[i] == '0' && t[i] == '1') {
			a01++;
		}
		if (s[i] == '1' && t[i] == '0') {
			a10++;
		}
		if (s[i] == '1' && t[i] == '1') {
			a11++;
		}
	}
	int ans1 = 0, ans2 = 0;
	forn (i, n) {
		if (a11) {
			ans1++;
			a11--;
		} else if (a10) {
			ans1++;
			a10--;
		} else if (a01) {
			a01--;
		} else {
			a00--;
		}
		if (a11) {
			ans2++;
			a11--;
		} else if (a01) {
			ans2++;
			a01--;
		} else if (a10) {
			a10--;
		} else {
			a00--;
		}
	}
	if (ans1 > ans2) {
		puts("First");
	} else if (ans1 < ans2) {
		puts("Second");
	} else {
		puts("Draw");
	}
	return 0;
}