#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void read() {
	int a, b, n;
	cin >> a >> b >> n;
	if (n % 3 == 0)
		cout << a << endl;
	else if (n % 3 == 1)
		cout << b << endl;
	else
		cout << (a ^ b) << endl;
}

void run() {

}

void write() {

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	read();
	run();
	write();
	return 0;
}