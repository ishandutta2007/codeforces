#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
int n, m;
int all[maxn];
int sg[maxn], a[maxn], ans[maxn];
struct T { int to, nxt; } way[maxn];
int h[maxn], num;
inline void link(int x,int y) {
	way[++num] = {y, h[x]}, h[x] = num;
}
inline void dfs(int x) {
	if(~sg[x]) return ;
	std::set<int> s;
	for(int i = h[x];i;i = way[i].nxt) {
		dfs(way[i].to);
		s.emplace(sg[way[i].to]);
	}
	for(sg[x] = 0;s.count(sg[x]);) ++sg[x];
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> a[i];
		sg[i] = -1;
	}
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		link(u, v);
	}
	rep(i, 1, n) {
		dfs(i);
		all[sg[i]] ^= a[i];
	}
	for(int x = n;x >= 0;--x) if(all[x]) {
		cout << "WIN" << '\n';
		rep(i, 1, n) if(sg[i] == x) {
			if((all[x] ^ a[i]) < a[i]) {
				a[i] ^= all[x], all[x] = 0;
				for(int j = h[i];j;j = way[j].nxt) {
					int to = way[j].to;
					a[to] ^= all[sg[to]];
					all[sg[to]] = 0;
				}
				goto output;
			}
		}
		output:
		rep(i, 1, n) {
			cout << a[i] << ' ';
		}
		return 0;
	}
	cout << "LOSE" << '\n';
}