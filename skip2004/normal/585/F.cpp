#include<bits/stdc++.h>
const int maxn = 1010;
const int mod = 1e9 + 7;
typedef long long ll;
inline ll pow(ll a,int b,ll ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1) ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
inline void reduce(int & x){ x += x >> 31 & mod; }
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
std::string s, x, y;
int d;
int son[maxn * 25][10], fail[maxn * 25], ok[maxn * 25], tot = 0;
inline void build(std::string s) {
	for(int i = 0;i + (d >> 1) <= s.size();++i) {
		int rt = 0;
		for(int j = i;j < i + (d >> 1);++j) {
			int & x = son[rt][s[j] - '0'];
			if(!x) x = ++ tot;
			rt = x;
		}
		ok[rt] = 1;
	}
	std::queue<int> q;
	for(int i = 0;i < 10;++i) if(i[*son]) q.push(i[*son]);
	for(;!q.empty();){ 
		int x = q.front(); q.pop();
		for(int i = 0;i < 10;++i)
			if(son[x][i]) fail[son[x][i]] = son[fail[x]][i], q.push(son[x][i]);
			else son[x][i] = son[fail[x]][i];
	}
	for(int i = 1;i <= tot;++i) if(ok[i])
		for(int j = 0;j < 10;++j) son[i][j] = i;
}
int dp[55][maxn * 25][2];
int ch[maxn];
inline int dfs(int a,int t,int hi) {
	if(a == d) return ok[t];
	int & ans = dp[a][t][hi];
	if(~ans) return ans;
	ans = 0;
	for(int i = a == 0;i <= (hi ? ch[a] : 9);++i)
		reduce(ans += dfs(a + 1,son[t][i],hi && i == ch[a]) - mod);
	return ans;
}
inline int calc(std::string s) {
	memset(dp, -1, sizeof dp);
	for(int i = 0;i < s.size();++i)
		ch[i] = s[i] - '0';
	return dfs(0, 0, 1);
}
inline bool chk(std::string s) {
	int rt = 0; for(auto i : s) rt = son[rt][i - '0']; return ok[rt];
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> s >> x >> y, d = x.size();
	build(s);
	int ans = calc(y) - calc(x) + chk(x);
	std::cout << ans + (ans >> 31 & mod) << '\n';
}