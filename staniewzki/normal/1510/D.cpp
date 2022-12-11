#include <bits/stdc++.h> // Tomasz Nowak
using namespace std;     // University of Warsaw
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ssize(x) int((x).size())
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
	return o << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
	o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#ifdef DEBUG
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define debug(...) {}
#endif

ostream& operator<<(ostream &o, tuple<int, int, int> &t) {
	return o << vector{get<0>(t), get<1>(t), get<2>(t)};
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, d;
	cin >> n >> d;
	using LD = long double;
	constexpr LD eps = 0.5;
	vector dp(n + 1, vector<LD>(10, -1));
	vector from(n + 1, vector<tuple<int, int, int>>(10, {-1, -1, -1}));
	dp[0][1] = 0;

	vector<int> input;

	FOR(i, 1, n) {
		int ai;
		cin >> ai;
		input.emplace_back(ai);
		dp[i] = dp[i - 1];
		from[i] = from[i - 1];
		FOR(prev, 0, 9)
			if(dp[i - 1][prev] > -eps) {
				int next = (prev * ai) % 10;
				if(dp[i - 1][prev] + log(ai) > dp[i][next]) {
					dp[i][next] = dp[i - 1][prev] + log(ai);
					from[i][next] = make_tuple(i - 1, ai, prev);
				}
			}
	}
	debug(dp);
	debug(from);

	if(get<0>(from[n][d]) == -1) {
		if(d == 1 and *min_element(input.begin(), input.end()) == 1) {
			cout << "1\n1\n";
			return 0;
		}
		cout << "-1\n";
		return 0;
	}

	vector<int> out;
	int i = n;
	while(get<0>(from[i][d]) != -1) {
		auto [prev_i, ai, prev_d] = from[i][d];
		out.emplace_back(ai);
		i = prev_i;
		d = prev_d;
	}

	sort(out.begin(), out.end());
	cout << ssize(out) << '\n';
	for(int o : out)
		cout << o << ' ';
	cout << '\n';
}