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

char s[200100];

int main() {
	int n, t, dot = 0;
	cin >> n >> t >> s;
	forn (i, n) {
		if (s[i] == '.') {
			dot = i + 1;
			break;
		}
	}
	for (int i = dot; i < n; ++i) {
		if (s[i] < '5') {
			continue;
		}
		int j = i - 1;
		for (; j >= dot && s[j] == '4'; --j);
		j = max(j, i - t);
		++j;
		s[j] = 0;
		for (int k = j - 1; k >= 0; --k) {
			if (s[k] == '.') {
				s[k] = 0;
				continue;
			}
			if (s[k] < '9') {
				++s[k];
				break;
			}
			if (k < dot) {
				s[k] = '0';
			} else {
				s[k] = 0;
			}
			if (k == 0) {
				cout << 1;
			}
		}
		break;
	}
	cout << s;
    return 0;
}