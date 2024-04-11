#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXP = 1e7 + 288;
int lp[MAXP];
vector<int> pr;

void build() {
	for (int i = 2; i < MAXP; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] * i < MAXP && pr[j] <= lp[i]; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
}

const int MAXN = 5e5 + 10;
int n;
int a[MAXN];

void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int ans[MAXN][2];

void run() {
	for (int i = 0; i < n; i++) {
		int x = a[i], y = 1;
		while (lp[a[i]] == lp[x] && lp[a[i]]) {
			x /= lp[a[i]];
			y *= lp[a[i]];
		} 
		if (__gcd(x + y, a[i]) != 1 || x == 1 || y == 1) {
			ans[i][0] = ans[i][1] = -1;
		} else {
			ans[i][0] = x;
			ans[i][1] = y;
		}
	}
}

void write() {
	for (int it = 0; it < 2; it++){
		for (int i = 0; i < n; i++) {
			cout << ans[i][it] << " ";
		}
		cout << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	build();
	read();
	run();
	write();
	return 0;
}