#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second



int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	int j = 0;
	forn (i, k) {
		while (j < n - 1 && (s[j] != '4' || s[j + 1] != '7')) {
			j++;
		}
		if (j == n - 1) {
			break;
		}
		if ((j & 1) == 0) {
			if (j < n - 2 && s[j + 2] == '7') {
				if ((k - i) & 1) {
					s[j + 1] = '4';
				} else {
					s[j + 1] = '7';
				}
				break;
			}
			s[j + 1] = '4';
		} else {
			if (j > 0 && s[j - 1] == '4') {
				if ((k - i) & 1) {
					s[j] = '7';
				} else {
					s[j] = '4';
				}
				break;
			}
			s[j] = '7';
		}
	}
	cout << s;
}