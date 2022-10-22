#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
typedef std::pair<int, int> pr;
int n, m;
struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
int dfn[maxn], low[maxn], tot, cnt;
bool can_del[maxn];
inline void clear() {
	memset(dfn + 1, 0, n << 2);
	memset(h + 1, 0, n << 2);
	cnt = tot = num = 0;
}
inline void down(int & x,int y) {
	if(x > y) {
		x = y;
	}
}
inline void dfs(int x, int fa = 0) {
	dfn[x] = low[x] = ++tot;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		if(!dfn[way[i].to]) {
			dfs(way[i].to, x);
			down(low[x], low[way[i].to]);
		} else {
			down(low[x], dfn[way[i].to]);
		}
	}
	cnt += low[x] == dfn[x];
}
pr edge[maxn];
std::vector<pr> ans;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m;++i) {
		cin >> edge[i].first >> edge[i].second;
	}
	ans = std::vector<pr>(edge, edge + m);
	size_t t = clock();
	std::mt19937 rd(114514);
	do {
		std::shuffle(edge, edge + m, rd);
		memset(can_del, 0, n);
		for(int i = 0;i < m;++i) {
			clear();
			can_del[i] = 1;
			for(int j = 0;j < m;++j) if(!can_del[j]) {
				link(edge[j].first, edge[j].second);
			}
			dfs(1);
			if(cnt != 1) {
				can_del[i] = 0;
				continue;
			}
			for(int j = 1;j <= n;++j) if(!dfn[j]) {
				can_del[i] = 0;
				break;
			}
		}
		static std::vector<pr> vc;
		for(int i = 0;i < m;++i) if(!can_del[i]){ 
			vc.push_back(edge[i]);
		}
		if(vc.size() < ans.size()) {
			ans = vc;
		}
		vc.clear();
	} while(double(clock() - t) / CLOCKS_PER_SEC < 0.5);
	cout << ans.size() << '\n';
	for(pr i : ans) {
		cout << i.first << ' ' << i.second << '\n';
	}
}