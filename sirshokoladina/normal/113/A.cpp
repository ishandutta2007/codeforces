#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

string s;
int a[100010];

string o[7] = {"lios", "etr", "initis", "liala", "etra", "inites", ""};

int f(string s) {
	forn(i, 7) {
		if (s.size() >= o[i].size()) {
			bool ok = 1;
			forn(j, o[i].size()) {
				ok &= (o[i][j] == s[s.size() - o[i].size() + j]);
			}
			if (ok)
				return i;
		}
	}
	return 6;
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int n = 0;
	while (cin >> s) {
		a[n] = f(s);
		if (a[n] == 6) {
			cout << "NO";
			return 0;
		}
		n++;
	}
	if (n == 0) {
		cout << "NO";
		return 0;
	}
	if (n == 1) {
		cout << "YES";
		return 0;
	}
	forn(i, n - 1) {
		if (a[i] / 3 != a[i + 1] / 3) {
			cout << "NO";
			return 0;
		}
	}
	forn(i, n) {
		a[i] %= 3;
	}
	if (a[0] == 2) {
		cout << "NO";
		return 0;
	}
	if (a[n - 1] == 0) {
		cout << "NO";
		return 0;
	}
	forn(i, n - 1) {
		if (a[i] == 0 && a[i + 1] == 2 ||
		    a[i] == 1 && a[i + 1] == 0 ||
			a[i] == 1 && a[i + 1] == 1 ||
			a[i] == 2 && a[i + 1] == 0 ||
			a[i] == 2 && a[i + 1] == 1) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}