#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
 
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
 
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a){
		cin >> i;
		i--;
	}
	set<int> have;
	for (auto i : a)
		have.insert(i);
	map<int, int> coord;
	int cnt = 0;
	for (auto i : have)
		coord[i] = cnt++;
	for (auto &i : a)
		i = coord[i];
 
	vector<int> first(n, -1), last(n, -1);
	for (int i = 0; i < n; i++) {
		if (first[a[i]] == -1)
			first[a[i]] = i;
		last[a[i]] = i;
	}
 
	int pos_l = 0, pos_r = 1;
	int ans = 0;
	while (pos_l < n && first[pos_l] != -1) {
		//cout << pos_l << " " << pos_r << endl;
		while (pos_r < n && first[pos_r] >= last[pos_r - 1])
			pos_r++;
		chkmax(ans, pos_r - pos_l);
		pos_l = pos_r;
		pos_r++;
	}
	cout << cnt - ans << "\n";
}
 
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}