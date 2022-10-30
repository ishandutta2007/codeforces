#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
class edge {
public:
	int to, cap, rev;
	edge() : to(-1), cap(0), rev(-1) {};
	edge(int to_, int cap_, int rev_) : to(to_), cap(cap_), rev(rev_) {};
};
class maxflow {
private:
	vector<vector<edge> > G;
	vector<bool> vis;
	int find_augment(int pos, int tar, int curflow) {
		if (pos == tar) return curflow;
		vis[pos] = true;
		for (edge &e : G[pos]) {
			if (!vis[e.to] && e.cap > 0) {
				int res = find_augment(e.to, tar, min(curflow, e.cap));
				if (res > 0) {
					e.cap -= res;
					G[e.to][e.rev].cap += res;
					return res;
				}
			}
		}
		return 0;
	}
public:
	maxflow() : G(vector<vector<edge> >()) {};
	maxflow(int N) : G(vector<vector<edge> >(N)) {};
	void add_edge(int a, int b, int cap) {
		G[a].push_back(edge(b, cap, G[b].size()));
		G[b].push_back(edge(a, 0, G[a].size() - 1));
	}
	int get_maxflow(int src, int tar) {
		int ans = 0;
		while (true) {
			vis = vector<bool>(G.size(), false);
			int res = find_augment(src, tar, inf);
			if (res == 0) break;
			ans += res;
			if (ans >= inf) {
				ans = inf;
				break;
			}
		}
		return ans;
	}
};
int solve(int N, int M, vector<int> A, vector<int> even, vector<int> odd) {
	maxflow F(N + 2);
	for (int i = 0; i < N; ++i) {
		if (i % 2 == 0) F.add_edge(N, i, A[i]);
		else F.add_edge(i, N + 1, A[i]);
	}
	for (int i = 0; i < M; ++i) {
		F.add_edge(even[i], odd[i], inf);
	}
	return F.get_maxflow(N, N + 1);
}
int main() {
	int N, M;
	cin >> N >> M;
	maxflow F(N + 2);
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> X(M), Y(M);
	for (int i = 0; i < M; ++i) {
		cin >> X[i] >> Y[i]; --X[i], --Y[i];
		if (X[i] % 2 == 1) swap(X[i], Y[i]);
	}
	map<int, vector<int> > v;
	for (int i = 0; i < N; ++i) {
		map<int, int> d;
		int c = A[i];
		for (int j = 2; j * j <= c; ++j) {
			while (c % j == 0) {
				c /= j;
				++d[j];
			}
		}
		if (c > 1) ++d[c];
		for (pair<int, int> j : d) {
			if (v.find(j.first) == v.end()) {
				v[j.first] = vector<int>(N, 0);
			}
			v[j.first][i] += j.second;
		}
	}
	int ans = 0;
	for (pair<int, vector<int> > i : v) {
		ans += solve(N, M, i.second, X, Y);
	}
	cout << ans << endl;
	return 0;
}