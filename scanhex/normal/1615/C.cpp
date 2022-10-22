#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int oo = 0x3f3f3f3f;

int solve(int c00, int c01, int c10, int c11, int d = 10) {
	if (c00 < 0 || c01 < 0 || c10 < 0 || c11 < 0) 
		return oo;

	if (d == 0) 
		return oo;
	if (c01 == 0 && c10 == 0) return 0;
	vector<array<int, 4>> v;
	v.push_back({c10 - 1, c11, 1 + c00, c01});
	v.push_back({c10, c11 - 1, c00, 1 + c01});
	int res = oo;
	for(auto& [c00, c01, c10, c11] : v) res = min(res, 1 + solve(c00, c01, c10, c11, d - 1));
	return res;
}

int b(int,int,int,int);
int a(int c00, int c01, int c10, int c11) {
	if (c01 == 0 && c10 == 0) return 0;
	if (c10 == 0 && c11 == 0) return oo;
	if (c10 == 0) return oo;
	return 1 + b(c10 - 1, c11, 1 + c00, c01);
}
int b(int c00, int c01, int c10, int c11) {
	if (c01 == 0 && c10 == 0) return 0;
	if (c10 == 0 && c11 == 0) return oo;
	if (c11 == 0) return oo;
	return 1 + a(c10, c11 - 1, c00, 1 + c01);
}

int mysolve(int c00, int c01, int c10, int c11) {
	if (c01 == 0 && c10 == 0) return 0;
	if (c10 == 0 && c11 == 0) return -1;
	int res = oo;
	res = min(res, a(c00, c01, c10, c11));
	res = min(res, b(c00, c01, c10, c11));
	if (res == oo) res = -1;
	return res;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n; 
		n = 7;
		cin >> n;

		string s1, s2;
		s1.resize(n);
		s2.resize(n);
		for(int i = 0; i < n;++i) {
			s1[i] = rand() % 2 + '0';
			s2[i] = rand() % 2 + '0';
		}
//		cout << s1 << ' ' << s2 << ' ';
		cin >> s1 >> s2;
		array<array<int, 2>, 2> c = {};
		for(int i = 0; i < n; ++i) 
			c[s1[i] - '0'][s2[i] - '0']++;
		cout << mysolve(c[0][0], c[0][1], c[1][0], c[1][1]) << '\n';
		continue;
		if (s1 == s2) {
			cout << 0 << '\n';
			continue;
		}
		if (count(s1.begin(), s1.end(), '1') == 0) {
			cout << -1 << '\n';
			continue;
		}
		if (count(s2.begin(), s2.end(), '1') == 0) {
			cout << -1 << '\n';
			continue;
		}
		int res = oo;
		int ceven = 0, codd = 0;
		int geven = 0, godd = 0;
		for(int i = 0; i < n; ++i) {
			if (s1[i] == s2[i]) {
				if (s1[i] == '1')
					ceven++;
				else
					codd++;
			}
			else {
				if (s1[i] == '1') 
					++geven;
				else 
					++godd;
			}
		}
		if (ceven > codd && godd + codd >= ceven - 1  && (ceven + codd) % 2 == 1) {
			res = min(res, ceven + ceven - 1);
		}
		if (ceven == codd + 1) 
			res = min(res, ceven + codd);
		if (ceven < codd && geven + ceven >= codd + 1 && (ceven + codd) % 2 == 1) {
			res = min(res, codd + codd + 1);
		}
		ceven = 0, codd = 0;
		geven = 0, godd = 0;
		for(int i = 0; i < n; ++i) {
			if (s1[i] != s2[i]) {
				if (s1[i] == '1')
					ceven++;
				else
					codd++;
			}
			else {
				if (s1[i] == '1') 
					++geven;
				else 
					++godd;
			}
		}
		if (ceven > codd && godd + codd >= ceven && (ceven + codd) % 2 == 0) {
			res = min(res, ceven + ceven);
		}
		if (ceven == codd) 
			res = min(res, ceven + codd);
		if (ceven < codd && geven + ceven >= codd && (ceven + codd) % 2 == 0) {
			res = min(res, codd + codd);
		}
		if (res == oo) res = -1;
		cout << res << '\n';
	}
}