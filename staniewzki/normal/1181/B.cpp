#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define ST first
#define ND second
#define EB emplace_back
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#ifdef DEBUG
template<class T> int size(T &&x) {
	return int(x.size());
}
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int l;
	cin >> l;
	string str;
	cin >> str;

	int m1 = -1, m2 = -1;
	int m = (l - 1) / 2;
	while(m != -1 && str[m] == '0') m--;
	m1 = m;
	m = (l + 1) / 2;
	while(m != l && str[m] == '0') m++;
	m2 = m;

	debug(m1, m2);

	auto add = [&](string a, string b)
	{
		debug(a, b);
		string ret;
		int p = 0;
		while(!a.empty() && !b.empty())
		{
			int x = a.back() + b.back() - '0' * 2 + p;
			if(x >= 10) p = 1, x -= 10;
			else p = 0;
			a.pop_back();
			b.pop_back();
			ret.push_back(x + '0');
		}

		if(a.empty()) swap(a, b);
		while(!a.empty())
		{
			int x = a.back() - '0' + p;
			if(x >= 10) p = 1, x -= 10;
			else p = 0;

			ret.push_back(x + '0');
			a.pop_back();
		}

		if(p) ret.push_back('1');
		reverse(ret.begin(), ret.end());
		debug(ret);
		return ret;
	};

	auto split = [&](int s)
	{
		string left, right;
		REP(i, s) left.push_back(str[i]);
		FOR(i, s, l - 1) right.push_back(str[i]);
		debug(s, left, right);
		return add(left, right);
	};

	auto get = [&]()
	{
		if(m1 == -1 || m1 == 0) return split(m2);
		if(m2 == l) return split(m1);
		string s1 = split(m1);
		string s2 = split(m2);
		debug(s1, s2);
		if(s1.size() < s2.size()) return s1;
		if(s1.size() > s2.size()) return s2;
		REP(i, s1.size())
		{
			if(s1[i] < s2[i]) return s1;
			if(s1[i] > s2[i]) return s2;
		}
		return s1;
	};

	cout << get() << "\n";
}