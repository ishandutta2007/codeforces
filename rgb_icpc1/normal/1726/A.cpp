#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
#define pb push_back
 
template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
using LL = long long;
using PI = pair<int, int>;
using VI = vector<int>;
const int N = 1000005;

int a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T --) {
		int n; cin >> n;
		int mx = 0, mn = INT_MAX;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			if (i > 0) chkmax(mx, a[i]);
			if (i < n - 1) chkmin(mn, a[i]);
		}
		int rlt = mx - a[0];
		chkmax(rlt, a[n - 1] - mn);
		chkmax(rlt, a[n - 1] - a[0]);
		for (int i = 0; i < n; i ++) {
			chkmax(rlt, a[(i - 1 + n) % n] - a[i]);
		}
		cout << rlt << endl;
	}
	return 0;
}