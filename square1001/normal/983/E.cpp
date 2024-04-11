#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class RangeQuery2D {
	int sz;
	vector<int> comp;
	vector<vector<int> > seg;
public:
	RangeQuery2D() : sz(0), comp(vector<int>()), seg(vector<vector<int> >()) {};
	RangeQuery2D(vector<pair<int, int> > points) {
		sz = 1;
		while (sz < points.size()) sz *= 2;
		sort(points.begin(), points.end());
		comp.resize(points.size());
		seg = vector<vector<int> >(sz * 2);
		for (int i = 0; i < points.size(); ++i) {
			comp[i] = points[i].first;
			int cur = i + sz;
			while (cur >= 1) {
				seg[cur].push_back(points[i].second);
				cur >>= 1;
			}
		}
		for (int i = 1; i < sz; ++i) {
			sort(seg[i].begin(), seg[i].end());
		}
	}
	int count(int xa, int ya, int xb, int yb) {
		int l = lower_bound(comp.begin(), comp.end(), xa) - comp.begin();
		int r = lower_bound(comp.begin(), comp.end(), xb) - comp.begin();
		l += sz; r += sz;
		int ans = 0;
		while (l != r) {
			if (l & 1) ans += lower_bound(seg[l].begin(), seg[l].end(), yb) - lower_bound(seg[l].begin(), seg[l].end(), ya), ++l;
			if (r & 1) --r, ans += lower_bound(seg[r].begin(), seg[r].end(), yb) - lower_bound(seg[r].begin(), seg[r].end(), ya);
			l >>= 1; r >>= 1;
		}
		return ans;
	}
};
int N, M, Q, counter, bits; vector<int> D, sl, sr; vector<vector<int> > G, P, V;
vector<vector<pair<int, int> > > points;
vector<RangeQuery2D> RQ;
void euler_tour(int pos, int pre) {
	sl[pos] = counter++;
	for (int i : G[pos]) {
		if (i == pre) continue;
		euler_tour(i, pos);
	}
	sr[pos] = counter;
}
int lca(int va, int vb) {
	if (D[va] < D[vb]) swap(va, vb);
	for (int i = bits - 1; i >= 0; --i) {
		if (D[va] - D[vb] >= (1 << i)) {
			va = P[i][va];
		}
	}
	if (va == vb) return va;
	for (int i = bits - 1; i >= 0; --i) {
		if (P[i][va] != P[i][vb]) {
			va = P[i][va];
			vb = P[i][vb];
		}
	}
	return P[0][va];
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	while ((1 << bits) <= N) ++bits;
	P = vector<vector<int> >(bits, vector<int>(N));
	D.resize(N);
	G.resize(N);
	for (int i = 1; i < N; ++i) {
		cin >> P[0][i]; --P[0][i];
		G[i].push_back(P[0][i]);
		G[P[0][i]].push_back(i);
		D[i] = D[P[0][i]] + 1;
	}
	for (int i = 1; i < bits; ++i) {
		for (int j = 0; j < N; ++j) {
			P[i][j] = P[i - 1][P[i - 1][j]];
		}
	}
	sl.resize(N);
	sr.resize(N);
	euler_tour(0, -1);
	V = vector<vector<int> >(bits, vector<int>(N));
	for (int i = 0; i < N; ++i) V[0][i] = i;
	points.resize(N);
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		int x = lca(a, b);
		if (D[x] < D[V[0][a]]) V[0][a] = x;
		if (D[x] < D[V[0][b]]) V[0][b] = x;
		points[x].push_back(make_pair(sl[a], sl[b]));
	}
	RQ.resize(N);
	for (int i = 0; i < N; ++i) {
		RQ[i] = RangeQuery2D(points[i]);
	}
	for (int i = N - 1; i >= 1; --i) {
		if (D[V[0][P[0][i]]] > D[V[0][i]]) {
			V[0][P[0][i]] = V[0][i];
		}
	}
	for (int i = 1; i < bits; ++i) {
		for (int j = 0; j < N; ++j) {
			V[i][j] = V[i - 1][V[i - 1][j]];
		}
	}
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		if (D[a] < D[b]) swap(a, b);
		int x = lca(a, b);
		if (a == b) {
			cout << 0 << '\n';
		}
		else if (x == b) {
			int ans_special = 0;
			for (int j = bits - 1; j >= 0; --j) {
				if (D[V[j][a]] > D[x]) {
					a = V[j][a];
					ans_special += 1 << j;
				}
			}
			a = V[0][a];
			++ans_special;
			if (D[a] > D[x]) cout << -1 << '\n';
			else cout << ans_special << '\n';
		}
		else {
			int ans = 0;
			for (int j = bits - 1; j >= 0; --j) {
				if (D[V[j][a]] > D[x]) {
					a = V[j][a];
					ans += 1 << j;
				}
				if (D[V[j][b]] > D[x]) {
					b = V[j][b];
					ans += 1 << j;
				}
			}
			if (D[V[0][a]] > D[x] || D[V[0][b]] > D[x]) {
				cout << -1 << '\n';
			}
			else {
				bool ok = false;
				int cnt1 = RQ[x].count(sl[a], sl[b], sr[a], sr[b]);
				int cnt2 = RQ[x].count(sl[b], sl[a], sr[b], sr[a]);
				if (cnt1 >= 1 || cnt2 >= 1) ++ans;
				else ans += 2;
				cout << ans << '\n';
			}
		}
	}
	return 0;
}