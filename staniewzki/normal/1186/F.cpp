#include<bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

template<class T> int size(T && a) {
	return a.size();
}

template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}

template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
	out << "{";
	for(auto it = a.begin(); it != a.end(); it = next(it))
		out << (it != a.begin() ? ", " : "") << *it;
	return out << "}";
}

void dump() { cerr << "\n"; }
template<class T, class... Ts> void dump(T a, Ts... x) {
	cerr << a << ", ";
	dump(x...);
}

#ifdef DEBUG
#  define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#  define debug(...) false
#endif

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second

mt19937_64 _gen(chrono::system_clock::now().time_since_epoch().count());
LL rd(LL a, LL b) { return uniform_int_distribution<LL>(a, b)(_gen); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<PII> edges(m);
	vector<int> deg(n);

	REP(i, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		deg[u]++, deg[v]++;
		edges[i] = {u, v};
	}

	random_shuffle(edges.begin(), edges.end(), [](int a) { return rd(0, a - 1); });

	vector<int> f = deg;
	vector<PII> out;
	REP(i, m) {
		auto check = [&](int v) {
			return ((deg[v] + 1) / 2 <= f[v] - 1);
		};

		PII a = edges[i];
		if(check(a.ST) && check(a.ND))
			f[a.ST]--, f[a.ND]--;
		else
			out.emplace_back(a.ST + 1, a.ND + 1);
	}

	cout << size(out) << "\n";
	for(auto &p : out)
		cout << p.ST << " " << p.ND << "\n";
}