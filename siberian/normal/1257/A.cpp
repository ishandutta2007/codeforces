#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void read() {

}

void run() {
	int n, x, a, b;
	cin >> n >> x >> a >> b;
	if (a > b) swap(a, b);
	int fx = max(a - x, 1LL);
	x -= a - fx;
	a = fx;
	fx = min(n, b + x);
	b = fx;
	cout << b - a << endl;
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
		run();
	return 0;
}