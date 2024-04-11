#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void read() {
	int q;
	cin >> q;
	while (q--) {
		string s, t;
		cin >> s >> t;
		set<char> x;
		for (auto i : s)
			x.insert(i);
		bool flag = false;
		for (auto i : t)
			flag |= x.count(i);
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

void run() {

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