#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;
const int MN = 1000005;
const int M = 998244353;

int n;
string s, s1, s2;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int Tc;
	for (cin >> Tc; Tc--; ) {
		cin >> n >> s;
		if (s[0] != '1' || s[n - 1] != '1') {
			cout << "NO" << endl;
			continue;
		}
		int j0 = 0, j1 = 0;
		s1.clear(); s2.clear();
		s1 += '(', s2 += '(';
		for (int i = 1; i < n - 1; i++) {
			if (s[i] == '0') {
				j0++;
				if (j0 & 1) s1 += '(', s2 += ')';
				else s1 += ')', s2 += '(';
			}
			else {
				j1++;
				if (j1 & 1) s1 += '(', s2 += '(';
				else s1 += ')', s2 += ')';
			}
		}
		if (j0 & 1) {
			cout << "NO" << endl;
			continue;
		}
		s1 += ')', s2 += ')';
		cout << "YES" << endl;
		cout << s1 << endl << s2 << endl;
	}

	return 0;
}