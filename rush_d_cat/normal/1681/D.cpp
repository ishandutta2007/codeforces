#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, x, ans = 1e9;
//map<ll, int> mp;

void dfs(ll cur, ll dep) {
	//if (mp.find(cur) != mp.end()) return;
	auto s = to_string(cur);

	if (s.length() == n) {
		ans = min(ans, dep);
		return;
	}

	if (s.length()  > n) return;
	if (dep + n - s.length() >= ans) return;
	//cout << cur << " " << dep << "\n";
	sort(s.begin(),s.end());
	s.erase(unique(s.begin(),s.end()),s.end());
	reverse(s.begin(),s.end());
	for (auto c: s) if (c >= '2') dfs(cur * (c-'0'), dep + 1);
	//mp[cur] = 1;
}	

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	cin >> n >> x;
	dfs(x, 0);
	if (ans == 1e9) cout << -1 << "\n";
	else cout << ans << "\n";
	
}