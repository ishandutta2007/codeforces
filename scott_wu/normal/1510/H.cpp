#include <bits/stdc++.h>

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }

template <typename T> void ensure_size(std::vector<T>& a, int sz, T t) {
	if (int(a.size()) < sz) {
		a.resize(sz, t);
	}
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<array<int, 2>> A(N); for (auto& a : A) cin >> a[0] >> a[1];

	int V = N;
	vector<array<vector<pair<int, int>>, 4>> dp(2*N-1); // the second int is used for backtracking
	vector<array<int, 2>> rng(2*N-1);
	vector<array<int, 2>> ch(2*N-1);
	for (int i = 0; i < N; i++) {
		rng[i] = A[i];
		for (int z = 0; z < 4; z++) {
			dp[i][z] = {{A[i][1] - A[i][0], -1}};
		}
	}
	auto merge_adj = [&](int a, int b) -> int {
		int c = V++;
		ch[c] = {a,b};
		rng[c] = {rng[a][0], rng[b][1]};
		for (int z = 0; z < 4; z++) {
			auto& dpc = dp[c][z];
			// d is whether we leave the middle guy as a hole or not
			for (int d = 1; d >= 0; d--) {
				int za = (z & 1) + 2 * d;
				int zb = d + (z & 2);
				const auto& dpa = dp[a][za];
				const auto& dpb = dp[b][zb];
				ensure_size(dpc, int(dpa.size())-1 + int(dpb.size())-1 + d + 1, {-1, 0});
				for (int x = 0; x < int(dpa.size()); x++) {
					for (int y = 0; y < int(dpb.size()); y++) {
						setmax(dpc[x+y+d],
							{dpa[x].first + dpb[y].first + (d ? rng[b][0] - rng[a][1] : 0), 2 * x + d});
					}
				}
			}
		}
		return c;
	};
	auto merge_ch = [&](int a, int p) -> int {
		int c = V++;
		assert(p < N);
		ch[c] = {a,p};
		rng[c] = rng[p];
		for (int z = 0; z < 4; z++) {
			auto& dpc = dp[c][z];
			// we can either be in the middle, on the left, or on the right
			{
				// in the middle
				int za = z;
				int extra = (za & 1 ? rng[a][0] - rng[p][0] : 0) + (za & 2 ? rng[p][1] - rng[a][1] : 0);
				const auto& dpa = dp[a][za];
				ensure_size(dpc, int(dpa.size())-1, {-1, 0});
				for (int v = 1; v < int(dpa.size()); v++) {
					setmax(dpc[v-1], {dpa[v].first + extra, 0});
				}
			}

			{
				// on the left
				int za = z | 1;
				int extra = (za & 1 ? rng[a][0] - rng[p][0] : 0) + (za & 2 ? rng[p][1] - rng[a][1] : 0);
				const auto& dpa = dp[a][za];
				ensure_size(dpc, int(dpa.size()), {-1, 0});
				for (int v = 0; v < int(dpa.size()); v++) {
					setmax(dpc[v], {dpa[v].first + extra, 1});
				}
			}

			{
				// on the right
				int za = z | 2;
				int extra = (za & 1 ? rng[a][0] - rng[p][0] : 0) + (za & 2 ? rng[p][1] - rng[a][1] : 0);
				const auto& dpa = dp[a][za];
				ensure_size(dpc, int(dpa.size()), {-1, 0});
				for (int v = 0; v < int(dpa.size()); v++) {
					setmax(dpc[v], {dpa[v].first + extra, 2});
				}
			}
		}
		return c;
	};

	// sort by length
	vector<int> segs(N); iota(segs.begin(), segs.end(), 0);
	sort(segs.begin(), segs.end(), [&](int a, int b) { return A[a][1] - A[a][0] < A[b][1] - A[b][0]; });
	map<int, int> intervals; // left endpoints
	for (int a : segs) {
		auto it = intervals.lower_bound(A[a][0]);
		auto jt = intervals.lower_bound(A[a][1]);
		while (it != jt && std::next(it) != jt) {
			it->second = merge_adj(it->second, std::next(it)->second);
			intervals.erase(std::next(it));
		}
		if (it != jt) {
			a = merge_ch(it->second, a);
			intervals.erase(it);
		}
		intervals.insert({rng[a][0], a});
	}

	vector<array<int, 2>> ans(N, {-1, -1});

	vector<int> extras; extras.reserve(N);
	auto restore = std::y_combinator([&](auto self, int c, int cur_left, int cur_right, int num_extra) -> void {
		assert(int(extras.size()) >= num_extra);
		int z = (cur_left != -1 ? 1 : 0) | (cur_right != -1 ? 2 : 0);
		assert(num_extra < int(dp[c][z].size()));
		if (cur_left != -1) {
			ans[cur_left][1] = rng[c][0];
		}
		if (cur_right != -1) {
			ans[cur_right][0] = rng[c][1];
		}

		if (c < N) {
			assert(num_extra == 0);
			ans[c] = A[c];
			return;
		}

		if (rng[ch[c][0]][1] < rng[ch[c][1]][0]) {
			// we're in a left/right thing
			int a = ch[c][0];
			int b = ch[c][1];
			int d = dp[c][z][num_extra].second & 1;
			int x = dp[c][z][num_extra].second >> 1;
			int y = num_extra - x - d;
			if (d) {
				// an extra guy is in the middle
				assert(num_extra >= 1);
				int m = extras.back(); extras.pop_back();
				self(a, cur_left, m, x);
				self(b, m, cur_right, y);
			} else {
				self(a, cur_left, -1, x);
				self(b, -1, cur_right, y);
			}
		} else {
			int a = ch[c][0];
			int p = ch[c][1];
			int d = dp[c][z][num_extra].second;
			if (d == 0) {
				// we're an extra
				extras.push_back(p);
				self(a, cur_left, cur_right, num_extra+1);
			} else if (d == 1) {
				ans[p][0] = A[p][0];
				self(a, p, cur_right, num_extra);
			} else if (d == 2) {
				ans[p][1] = A[p][1];
				self(a, cur_left, p, num_extra);
			} else assert(false);
		}
	});

	int tot = 0;
	for (auto [_, a] : intervals) {
		tot += dp[a][0][0].first;
		restore(a, -1, -1, 0);
	}

	cout << tot << '\n';
	for (int i = 0; i < N; i++) {
		cout << ans[i][0] << ' ' << ans[i][1] << '\n';
	}

	return 0;
}