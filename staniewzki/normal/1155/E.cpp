#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) for(int i = 0; i < a; i++)
#define EB emplace_back
#define ST first
#define ND second

using LL = long long;
using PII = pair<int, int>;

template<class T> ostream& operator<<(ostream &ost, vector<T> &vec)
{
	ost << "{";
	REP(i, vec.size()) ost << (i == 0 ? "" : ", ") << vec[i];
	return ost << "}";
}

template<class L, class R> ostream& operator<<(ostream &ost, pair<L, R> p)
{
	return ost << "(" << p.ST << ", " << p.ND << ")";
}

template<class T> void dump(const char *s, T a) { cerr << s << ": " << a << "\n"; }
template<class T, class... TS> void dump(const char *s, T a, TS... x)
{
	while(*s != ',') cerr << *s++;
	cerr << ": " << a;
	dump(s + 1, x...);
}

#ifdef DEBUG
#define DB(...) dump(#__VA_ARGS__, __VA_ARGS__)
#else
#define DB(...)
#endif

struct Berlekamp_Massey
{
	vector<int> x;
	int mod;
	
	LL qpow(LL a, LL b)
	{
		if(b == 0) return 1;
		if(b % 2 == 1) return a * qpow(a, b - 1) % mod;
		LL c = qpow(a, b / 2);
		return c * c % mod;
	}

	vector<int> get_recursion()
	{
		vector<int> curr, ls;
		LL lf = 0, ld = 0;

		for(int i = 0; i < x.size(); i++)
		{
			LL t = 0;
			for(int j = 0; j < curr.size(); j++)
				t = (t + (LL) x[i - 1 - j] * curr[j]) % mod;

			if((t - x[i]) % mod == 0) continue;
			if(curr.empty())
			{
				curr.resize(i + 1);
				lf = i;
				ld = (t - x[i]) % mod;
				continue;
			}

			LL k = (t - x[i]) * qpow(ld, mod - 2) % mod;
			vector<int> c(i - lf - 1);
			c.EB(k);
			for(int j = 0; j < ls.size(); j++)
				c.EB(- k * ls[j] % mod);

			if(c.size() < curr.size()) c.resize(curr.size());
			for(int j = 0; j < curr.size(); j++)
				c[j] = (c[j] + curr[j]) % mod;

			if(i - lf + (int)ls.size() >= (int)curr.size())
				ls = curr, lf = i, ld = (t - x[i]);

			curr = c;		
		}

		for(int &val : curr) val = (val % mod + mod) % mod;
		return curr;
	}

	vector<int> rec;

	void mull(vector<LL> &p, vector<LL> &q)
	{
		int m = rec.size();
		vector<LL> t(m * 2);

		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				t[i + j] = (t[i + j] + p[i] * q[j]) % mod;

		for(int i = m * 2 - 1; i >= m; i--)
			for(int j = m - 1; j >= 0; j--)
				t[i - j - 1] = (t[i - j - 1] + t[i] * rec[j]) % mod;

		for(int i = 0; i < m; i++)
			p[i] = t[i];
	}

	LL get_value(LL k)
	{
		if(rec.empty()) rec = get_recursion();
		int m = rec.size();

		vector<LL> s(m), t(m);
		s[0] = 1;
		if(m != 1) t[1] = 1;
		else t[0] = rec[0];

		while(k)
		{
			if(k % 2 == 1) mull(s, t);
			mull(t, t);
			k /= 2;
		}

		LL sum = 0;
		for(int i = 0; i < m; i++)
			sum = (sum + s[i] * x[i]) % mod;
		return (sum % mod + mod) % mod;
	}

	vector<int> get_all_values(int k)
	{
		if(rec.empty()) rec = get_recursion();
		int m = rec.size();

		vector<int> ret(k);
		for(int i = 0; i < k; i++)
		{
			if(i < x.size()) ret[i] = x[i];
			else
			{
				for(int j = 0; j < m; j++)
					ret[i] = (ret[i] + (LL) ret[i - j - 1] * rec[j]) % mod;
			}

			ret[i] = (ret[i] + mod) % mod;
		}

		return ret;
	}

	Berlekamp_Massey(vector<int> x, int mod = 1000696969) : x(x), mod(mod) {}
};

int main()
{
	ios_base::sync_with_stdio(0);

	int mod = 1e6 + 3;
	vector<int> x(50);
	REP(i, 50)
	{
		cout << "? " << i << endl;
		cin >> x[i];
	}

	Berlekamp_Massey BM(x, mod);

	LL ans = 0;
	for(int a : BM.get_all_values(mod))
	{
		if(a == 0)
		{
			cout << "! " << ans << endl;
			return 0;
		}
		else ans++;
	}

	cout << "! -1\n";
}