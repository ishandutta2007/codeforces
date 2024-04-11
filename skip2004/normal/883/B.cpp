#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = l;i <= r;++i)
using std::cin;
using std::cout;
const int maxn = 200100;
const int inf = 1e9;
std::vector<int> v0[maxn], v1[maxn], nu[maxn];
int n, m, k;
int max[maxn], min[maxn], vis[maxn];
int ans[maxn], mx[maxn], mn[maxn];
inline int gmax(int x) {
	if(vis[x]) puts("-1"), exit(0);
	if(mx[x]) return max[x];
	vis[x] = 1;
	for(int i : v1[x]) max[x] = std::min(max[x], gmax(i) - 1);
	vis[x] = 0, mx[x] = 1;
	return max[x];
}
inline int gmin(int x) {
	if(vis[x]) puts("-1"), exit(0);
	if(mn[x]) return min[x];
	vis[x] = 1;
	for(int i : v0[x]) min[x] = std::max(min[x], gmin(i) + 1);
	vis[x] = 0, mn[x] = 1;
	return min[x];
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, n) {
		cin >> max[i];
		if(!max[i]) {
			max[i] = k;
			min[i] = 1;
		} else {
			min[i] = max[i];
		}
	}
	rep(i, 1, m) {
		int x, y;
		cin >> x >> y;
		v0[x].push_back(y);
		v1[y].push_back(x);
	}
	rep(i, 1, n) if(gmax(i) < gmin(i) || gmax(i) < 1 || gmin(i) > k) {
		puts("-1"); return 0;
	}
	rep(i, 1, n) nu[gmax(i)].push_back(i);
	std::priority_queue<std::pair<int, int>> q;
	for(int i = k;i >= 1;--i) {
		for(int x : nu[i]) q.emplace(gmin(x), x);
		if(q.empty()) {
			puts("-1"); return 0;
		}
		ans[q.top().second] = i, q.pop();
		for(;q.size();) {
			int x = q.top().second;
			if(gmin(x) < i) break;
			q.pop(), ans[x] = i;
		}
	}
	rep(i, 1, n) {
		cout << ans[i] << ' ';
	}
}