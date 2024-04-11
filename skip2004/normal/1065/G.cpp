#include<bits/stdc++.h>
typedef long long ll;
const ll inf = 2e18;
using std::cin;
using std::cout;

int n, m;

inline ll add(ll x, ll y) {
	return x + y >= inf ? inf : x + y;
}

const int N = 1e7;
int ls[N], rs[N], tot;
ll size[N], cnt[N];

inline int merge(int x, int y) {
	if(!y) return x;
	if(!x) x = ++ tot;
	size[x] = add(size[x], size[y]);
	cnt[x] = add(cnt[x], cnt[y]);
	ls[x] = merge(ls[x], ls[y]);
	rs[x] = merge(rs[x], rs[y]);
	return x;
}

inline void add(int&x, int dep, ll c, const char*ch) {
	if(!x) x = ++ tot;
	int rt = x;
	size[rt] += c;
	for(;dep <= m && *ch;++ch) {
		int & x = rt[*ch & 1 ? rs : ls];
		if(!x) x = ++tot;
		size[rt = x] += c;
	}
	cnt[rt] += c;
}

inline void dfs(int &rt, int dep, const char *ch) {
	if(!rt) return ;
	dfs(ls[rt], dep + 1, ch);
	dfs(rs[rt], dep + 1, ch);
	if(cnt[rt]) {
		add(rt, dep, cnt[rt], ch);
		size[rt] -= cnt[rt], cnt[rt] = 0;
	}
}

ll k;
std::string s[1000];
void dfs(int & rt, ll k) {
	if(cnt[rt] >= k || m -- == 0) return ;
	k -= cnt[rt];
	if(k <= size[ls[rt]]) cout.put(48), dfs(ls[rt], k);
	else cout.put(49), dfs(rs[rt], k - size[ls[rt]]);
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> k >> m;
	int a = 0, b = 0;
	s[0] = "0";
	s[1] = "1";
	add(a, 0, 1, "0");
	add(b, 0, 1, "1");
	for(int i = 1;i < n;++i) {
		s[i + 1] = s[i - 1] + s[i];
		if(s[i + 1].size() > m) s[i + 1].resize(m);
		dfs(a, 0, s[i].data());
		int c = merge(a, b);
		a = b, b = c;
	}
	dfs(b, k);
}