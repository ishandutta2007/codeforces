#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <cassert>
 
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

const ll mod = 1000000007;
const int K = 330;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < 26; ++i) {
		if (s[i] == s[i + 1]) {
			cout << "Impossible\n";
			return 0;
		}
	}
	char ans[2][20];
	ans[0][13] = ans[1][13] = 0;
	for (int i = 0; i < 13; ++i) {
		ans[0][i] = ans[1][i] = '.';
	}
	for (int a = 0; a < 27; ++a) {
		for (int b = a + 1; b < 27; ++b) {
			if (s[a] != s[b]) {
				continue;
			}
			int x = (b - a - 1) / 2, y = 0;
			for (int i = a; i < b; ++i) {
				ans[y][x] = s[i];
				if (y == 0) {
					--x;
					if (x < 0) {
						x = 0;
						y = 1;
					}
				} else {
					++x;
				}
			}
//			cout << ans[0] << endl << ans[1] << endl;
			for (int i = b + 1; i < 27; ++i) {
				ans[y][x] = s[i];
				if (y == 1) {
					++x;
					if (x >= 13) {
						x = 12;
						y = 0;
					}
				} else {
					--x;
				}
			}
//			cout << ans[0] << endl << ans[1] << endl;
			for (int i = 0; i < a; ++i) {
				ans[y][x] = s[i];
				if (y == 1) {
					++x;
					if (x >= 13) {
						x = 12;
						y = 0;
					}
				} else {
					--x;
				}
			}
			cout << ans[0] << endl << ans[1] << endl;
		}
	}
    return 0;
}