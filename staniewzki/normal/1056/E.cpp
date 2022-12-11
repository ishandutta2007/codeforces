#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
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
template<class T> int size(T a) { return a.size(); }

struct Hashing
{
	vector<LL> ha, pw;
	LL mod = 1000696969;
	int base;

	Hashing(string &str) {
		base = rd(30, 50);
		int len = size(str);
		ha.resize(len + 1);
		pw.resize(len + 1, 1);
		REP(i, len) {
			ha[i + 1] = (ha[i] * base + str[i] - 'a' + 1) % mod;
			pw[i + 1] = (pw[i] * base) % mod;
		}
	}

	LL get_hash(int l, int r) {
		return ((ha[r + 1] - ha[l] * pw[r - l + 1]) % mod + mod) % mod;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;

	int n = size(t);
	Hashing hashing(t);	

	REP(i, n) for(int j = 0; j <= i; j++)
		debug(j, i, hashing.get_hash(j, i));

	int c0 = 0, c1 = 0;
	int m = size(s);
	REP(i, m) {
		if(s[i] == '0')
			c0++;
		else
			c1++;
	}

	int ans = 0;
	FOR(i, 1, n)
	{
		LL a = c0 * i;
		LL b = n - a;
		if(b <= 0) break;
		if(b % c1 != 0) continue;

		int j = b / c1;
		int p = 0;
		bool ok = true;
		LL h0 = -1, h1 = -1;
		REP(k, m)
		{
			if(s[k] == '0')
			{
				LL x = hashing.get_hash(p, p + i - 1);
				if(h0 == -1)
					h0 = x;
				else if(h0 != x)
				{
					ok = false;
					break;
				}
				p += i;
			}
			else
			{
				LL x = hashing.get_hash(p, p + j - 1);
				if(h1 == -1)
					h1 = x;
				else if(h1 != x)
				{
					ok = false;
					break;
				}
				p += j;
			}
		}

		if(ok && h0 != h1)
			ans++;
	}

	cout << ans << "\n";
}