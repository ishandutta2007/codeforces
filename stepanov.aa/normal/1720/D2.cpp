#pragma GCC optimize("Ofast,O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>


using namespace std;


#define ll int
#define pb push_back


const int mx_dp_sz = 30 * 3e5;



const int lgc = 30;


struct vrtx {
	array<int, 2> go;
	array<array<ll, 2>, 2> dp;

	vrtx() {
		for (int i = 0; i < 2; i += 1) {
			go[i] = -1;
			for (int j = 0; j < 2; j += 1) {
				dp[i][j] = 0;
			}
		}
	}

};


int n;
vector<ll> a;
array<vrtx, mx_dp_sz> dp;
int dpsz = 0;


int add_node() {
	dp[dpsz] = vrtx();
	return dpsz++;
}


void add(ll a, ll b, ll d) {
	int v = 0;
	for (int i = lgc - 1; i >= 0; i -= 1) {
		int ax = ((a >> i) & 1);
		int bx = ((b >> i) & 1);
		int cx = (ax ^ bx);
		dp[v].dp[ax][bx] = max(dp[v].dp[ax][bx], d);
		int& to = dp[v].go[cx];
		if (to == -1) {
			to = add_node();
		}
		v = to;
	}
}


ll get(ll a, ll b) {
	int v = 0;
	ll rs = 1;
	for (int i = lgc - 1; i >= 0 && v != -1; i -= 1) {
		int ax = ((a >> i) & 1);
		int bx = ((b >> i) & 1);
		int cx = (ax ^ bx);
		rs = max(rs, dp[v].dp[bx ^ 1][ax] + 1);
		v = dp[v].go[cx];
	}
	return rs;
}


ll solve() {
	dp[0] = vrtx();
	dpsz = 1;
	int rs = 0;
	for (int i = 0; i < n; i += 1) {
		int d = get(i, a[i]);
		rs = max(rs, d);
		add(i, a[i], d);
	}
	return rs;
}


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	// dp.resize(mx_dp_sz);
	while (t--) {
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; i += 1) {
			cin >> a[i];
		}
		cout << solve() << "\n";
	}
	return 0;
}