#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int n, cnt, _max;
string s;
char ansa, ansb;

int main() {
	cin >> n;
	cin >> s;
	s = " " + s;
	for (char a = 'A'; a <= 'Z'; a++) {
		for (char b = 'A'; b <= 'Z'; b++) {
			cnt = 0;
			for (int i = 2; i <= n; i++) {
				if (a == s[i - 1] && b == s[i]) {
					cnt++;
				}
			}
			if (_max < cnt) {
				_max = cnt;
				ansa = a;
				ansb = b;
			}
		}
	}
	cout << ansa << ansb << endl;
	return 0;
}

// By Sooke.
// CF977B Two-gram.