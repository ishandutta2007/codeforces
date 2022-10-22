#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
#define all(x) (x).begin(), (x).end()
using std::cin; using std::cout;
const int maxn = 8000200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n, m1, m2, t;
int a[maxn], b[maxn];
int dp[maxn][2];
short from[maxn][2];
bool ok[maxn][2];
int bak[maxn], tot;
inline bool up(int & x,int y){
	return x < y ? x = y, 1 : 0;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m1 >> m2 >> t, bak[tot = 1] = n + 1;
	rep(i, 1, m1) {
		cin >> a[i];
		bak[++tot] = a[i];
		bak[++tot] = a[i] + 1;
	}
	rep(i, 1, m2) {
		cin >> b[i];
		bak[++tot] = b[i];
		bak[++tot] = b[i] + 1;
	}
	std::sort(bak + 1, bak + tot + 1); tot = std::unique(bak + 1, bak + tot + 1) - bak - 1;
	rep(i, 1, m1) ok[std::lower_bound(bak + 1, bak + tot + 1, a[i]) - bak][0] = 1;
	rep(i, 1, m2) ok[std::lower_bound(bak + 1, bak + tot + 1, b[i]) - bak][1] = 1;
	rep(i, 0, tot) dp[i][0] = dp[i][1] = -1e9;
	dp[0][0] = 0;
	rep(i, 0, tot - 1) {
		if(i) ++ dp[i][0], ++ dp[i][1];
		rep(j, 0, 1) if(!ok[i][j ^ 1]) if(up(dp[i][j ^ 1], std::min(dp[i][j], t))) from[i][j ^ 1] = 1;
		rep(j, 0, 1) {
			const int v = dp[i][j] + bak[i + 1] - bak[i] - 1 - (ok[i + 1][j] ? t : 0);
			if(v >= 0 && up(dp[i + 1][j], v)) from[i + 1][j] = 2;
		}
	}
	if(dp[tot][0] >= 0 || dp[tot][1] >= 0) {
		cout << "Yes" << '\n';
		int i = tot, j = dp[tot][1] >= 0;
		std::vector<std::pair<int, int>> v0 = {{bak[i], j + 1}}, v;
		std::stack<int> s[2];
		for(;i || j;) {
			if(from[i][j] == 1) {
				v0.emplace_back(bak[i], (j ^= 1) + 1);
			} else {
				if(ok[i][j]) s[j].push(bak[i]);
				-- i;
			}
		}
		cout << v0.size() << '\n';
		sort(v0.begin(), v0.end());
		int first = t;
		for(auto i : v0) {
			int o = i.second - 1;
			for(;s[o].size() && s[o].top() <= i.first;s[o].pop()) {
				v.emplace_back(first, i.second);
				first += t;
			}
			cout << i.first << ' ';
			first = std::max(first, i.first);
		}
		cout << '\n';
		cout << v.size() << '\n';
		for(auto i : v) {
			cout << i.first << ' ' << i.second << '\n';
		}
		cout << '\n';
	} else {
		cout << "No" << '\n';
	}
}