#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
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
#ifdef DEBUG
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	deque<int> Q;
	REP(i, n)
	{
		int x;
		cin >> x;
		Q.emplace_back(x);
	}

	vector<pair<int, int>> beg(n);
	auto get_front = [&]() { int x = Q.front(); Q.pop_front(); return x; };
	REP(i, n)
	{
		int A = get_front();
		int B = get_front();
		Q.emplace_front(max(A, B));
		Q.emplace_back(min(A, B));
		beg[i] = {A, B};
	}

	vector<pair<int, int>> res(n - 1);
	int A = get_front();
	REP(i, n - 1)
	{
		int B = get_front();
		res[i] = {A, B};
	}

	REP(i, q)
	{
		LL x;
		cin >> x;
		pair<int, int> ans = {-1, -1};
		if(x <= n)
			ans = beg[x - 1];
		else
			ans = res[(x - n - 1) % (n - 1)];

		cout << ans.first << " " << ans.second << "\n";
	}
}