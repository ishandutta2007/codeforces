#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) for(int i = 0; i < a; i++)
#define EB emplace_back
#define ST first
#define ND second

using LL = long long;
using PII = pair<int, int>;

template<class L, class R> ostream& operator<<(ostream &ost, pair<L, R> p)
{
	return ost << "(" << p.ST << ", " << p.ND << ")";
}

template<class T> ostream& operator<<(ostream &ost, vector<T> &vec)
{
	ost << "{";
	REP(i, vec.size()) ost << (i == 0 ? "" : ", ") << vec[i];
	return ost << "}";
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

LL mod = 1e9 + 7;
LL fpow(LL a, LL n)
{
	if(n == 0) return 1;
	if(n % 2 == 1) return (a * fpow(a, n - 1)) % mod;
	LL ret = fpow(a, n / 2);
	return (ret * ret) % mod;
}

LL add(LL a, LL b) { return (a + b) % mod; }
LL mul(LL a, LL b) { return (a * b) % mod; }
LL divi(LL a, LL b) { return (a * fpow(b, mod - 2)) % mod; }

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n;
	cin >> n;

	vector<LL> in(n);
	REP(i, n)
		cin >> in[i];

	if(n == 1)
	{
		cout << in[0] << "\n";
		return 0;
	}

	int m = n / 2;
	vector<LL> b(m);
	b[0] = 1;
	FOR(k, 1, m - 1)
	{
		b[k] = mul(b[k - 1], m - k);
		b[k] = divi(b[k], k);
	}
	
	vector<LL> x(n);
	REP(i, n - (n % 2))
		x[i] = b[i / 2];

	if(n % 2 == 0)
	{
		if(n % 4 == 0)
			for(int i = 1; i < n; i += 2)
				x[i] *= -1;
	}
	else
	{
		auto y = x;
		y[0] = 0;
		FOR(i, 1, n - 1)
		{
			y[i] = x[i - 1];
			if(i % 2 == 0) y[i] *= -1;
		}

		DB(x, y);

		int q = (n % 4 == 3 ? 1 : -1);
		REP(i, n)
			x[i] = add(x[i], y[i] * q);
	}


	DB(x);
	LL ans = 0;
	REP(i, n)
		ans = add(ans, mul(x[i], in[i]));
	ans = add(ans, mod);
	cout << ans << "\n";
}