#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fs first
#define sc second
#define pb push_back

map<pair<int, int>, int> M;
int a[200100];
int b[200100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> s(n), t(m);
	forn (i, n) {
		cin >> s[i];
	}
	forn (i, m) {
		cin >> t[i];
	}
	int q;
	cin >> q;
	forn (i, q) {
		int x;
		cin >> x;
		x--;
		cout << s[x % n] << t[x % m] << endl;
	}
}