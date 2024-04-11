#include<bits/stdc++.h>
const int N = 2010;
using std::cin;
std::vector<int> to[N];
int size[N];
int n;
int min = 1e9, root;
inline void dfs0(int x, int fa = 0) {
	int max = 0;
	size[x] = 1;
	for(int i : to[x]) if(i != fa) {
		dfs0(i, x);
		size[x] += size[i];
		max = std::max(max, size[i]);
	}
	max = std::max(max, n - size[x]);
	if(max <= min) {
		min = max;
		root = x;
	}
}
struct set {
	std::vector<int> vc;
	int sum;
	inline int operator < (const set & b) const {
		return sum > b.sum;
	}
};
struct edge {
	int x, y, v;
	inline edge(int a0 = 0, int a1 = 0, int a2 = 0) { x = a0, y = a1, v = a2; }
};
std::vector<edge> vector;
inline void dfs1(int x, int vx, std::vector<int> & vc, int fa = 0) {
	for(int i : to[x]) if(i != fa) {
		const int vt = vc.front(); vc.erase(vc.begin());
		dfs1(i, vt, vc, x);
		vector.emplace_back(x, i, vt - vx);
	}
}
inline void make(std::vector<int> vc, std::vector<int> & need) {
	to[root].swap(vc);
	dfs1(root, 0, need);
	to[root].swap(vc);
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n;
	if(n == 1) return 0;
	for(int i = 1, x, y;i < n;++i) {
		cin >> x >> y;
		to[x].push_back(y);
		to[y].push_back(x);
	}
	dfs0(1);
	int x = root;
	dfs0(x);
	std::priority_queue<set> q;
	for(int i : to[x]) {
		q.push({{i}, size[i]});
	}
	for(;q.size() > 2;) {
		set x = q.top(); q.pop();
		set y = q.top(); q.pop();
		x.sum += y.sum;
		for(int i : y.vc) x.vc.push_back(i);
		q.push(x);
	}
	const int size = q.top().vc.size();
	const int M = 2 * n * n / 9;
	std::vector<int> v0, v1;
	for(int i = 1;i <= n;++i) v0.push_back(i);
	make(q.top().vc, v0), q.pop();
	if(q.size()) {
		const int size = n - v0.size() + 1;
		for(int i = 0;i <= n;++i) v1.push_back(size * (i + 1));
		make(q.top().vc, v1);
	}
	for(edge i : vector) {
		std::cout << i.x << ' ' << i.y << ' ' << i.v << '\n';
	}
}