#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
int n, k;
string s;

void read() {
	cin >> n >> k >> s;
}

void stupid(string a) {
	for (int i = 0; i < k; i++) {
		for (int j = i; j < n; j += k) {
			a[j] = a[i];
		}
	}
	if (a >= s) {
		cout << n << endl;
		cout << a << endl;
		exit(0);
	}
}

void run() {
	stupid(s);
	//cout << "puhh" << endl;
	for (int i = k - 1; i >= 0; i--) {
		if (s[i] != '9') {
			//cout << s << endl;
			s[i]++;
			//cout  << s << endl;
			for (int j = i; j < n; j += k)
				s[j] = s[i];
			//cout << s << endl;
			for (int pos = k - 1; pos > i; pos--)
				for (int j = pos; j < n; j += k)
					s[j] = '0';
			//cout << s << endl;
			for (int pos = i - 1; pos >= 0; pos--)
				for (int j = pos; j < n; j += k)
					s[j] = s[pos];
			cout << n << endl;
			cout << s << endl;
			exit(0);
		}
	}
	assert(false);
}

void write() {
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}