#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define ST first
#define ND second
#define EB emplace_back
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
template<class T> int size(T &&x) {
	return int(x.size());
}
#ifdef DEBUG
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == --x.end() ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
  const int seed = 1;
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (#x != "" ? #x ":  " : ""), dump(x), Nl(), cerr
#else
  const int seed = chrono::system_clock::now().time_since_epoch().count();
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(seed);
int rd(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<
	T,
	null_type,
	less<T>,
	rb_tree_tag,
	tree_order_statistics_node_update
>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	vector<PII> cities(m);
	REP(i, m)
		cities[i] = {0, i};

	vector<int> beg(n);
	REP(i, n)
	{
		cin >> beg[i];
		cities[beg[i] - 1].ST++;
	}

	sort(cities.begin(), cities.end());

	set<pair<LL, int>> Q;
	ordered_set<int> S;
	vector<LL> ans(q);
	REP(i, q)
	{
		LL x;
		cin >> x;
		if(x <= n) ans[i] = beg[x - 1];
		else Q.emplace(x - n - 1, i);
	}

	LL prev = 0;
	LL k = 0;
	REP(i, m - 1)
	{
		S.insert(cities[i].ND);
		if(cities[i].ST == cities[i + 1].ST) continue;
		LL len = i + 1;
		LL dif = cities[i + 1].ST - cities[i].ST;
		k += len * dif;

		while(Q.begin()->ST < k)
		{
			auto it = Q.begin();
			int index = (it->ST - prev) % len;
			ans[it->ND] = *S.find_by_order(index) + 1;
			Q.erase(Q.begin());
		}

		prev = k;
	}

	S.insert(cities[m - 1].ND);
	while(!Q.empty())
	{
		auto it = Q.begin();
		int index = (it->ST - prev) % m;
		ans[it->ND] = *S.find_by_order(index) + 1;
		Q.erase(Q.begin());
	}

	REP(i, q)
		cout << ans[i] << "\n";
}