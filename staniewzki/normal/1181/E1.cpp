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

struct rec {
	int x1, y1, x2, y2;
};

ostream& operator<<(ostream &out, rec r)
{
	return out << '[' << r.x1 << ' ' << r.y1 << ' ' << r.x2 << ' ' << r.y2 << ']';
}

bool good(vector<rec> s, bool swp)
{
	debug(s);
	if(size(s) <= 1) return true;
	if(swp) for(auto &r : s) swap(r.x1, r.y1), swap(r.x2, r.y2);
	sort(s.begin(), s.end(), [](rec i, rec j) { return i.x1 < j.x1; });
	int max_d = 0;
	int d = -1;
	vector<rec> to_check;
	REP(i, size(s))
	{
		if(i != 0 && max_d <= s[i].x1) {
			if(!good(to_check, true))
				return false;
			to_check.clear();
		}
		to_check.EB(s[i]);
		max_d = max(max_d, s[i].x2);
	}

	if(size(to_check) == size(s)) return false;
	return good(to_check, true);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<rec> s(n);
	REP(i, n)
		cin >> s[i].x1 >> s[i].y1 >> s[i].x2 >> s[i].y2;

	bool ok = good(s, false) | good(s, true);
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}