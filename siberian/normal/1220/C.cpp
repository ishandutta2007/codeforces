#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

string s;
int n;

bool used[26];

void read() {
	cin >> s;
	n = s.size();
}


bool check(int x) {
	for (int j = 0; j < x; j++)
		if (used[j])
			return true;
	return false;
}

void run() {
	for (int i = 0; i < n; i++) {
		if (check(s[i] - 'a'))
			cout << "Ann\n";
		else
			cout << "Mike\n";
		used[s[i] - 'a'] = true;
	}
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