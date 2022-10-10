#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
int a[MAXN], m[MAXN];

void solve(){
	int n, x;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = i - x;
	}
	x = 1;
	vector<int> ans;
	while(!m[x]) {
		m[x] = 1;
		x = a[x];
	}
	while(m[x]) {
		ans.push_back(x); m[x] = 0;
		x = a[x];
	}
	x = 1;
	while(m[x]) {
		m[x] = 0;
		x = a[x];
	}
	cout << ans.size() << '\n';
	for(auto e : ans) cout << e << " ";
	cout << '\n';
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
}