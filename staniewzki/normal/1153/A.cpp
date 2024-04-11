#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define V vector
#define EB emplace_back
#define ST first
#define ND second

template<class T> ostream& operator<<(ostream &ost, V<T> &vec)
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

using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n, t;
	cin >> n >> t;
	int ans = 1e9;
	int ret = -1;
	REP(i, n)
	{
		int s, d;
		cin >> s >> d;

		if(s >= t)
		{
			if(s < ans)
			{
				ans = s;
				ret = i;
			}
		}
		else
		{
			int q = t - s;
			DB(q);
			q = q / d + (q % d != 0);
			int x = s + q * d;
			DB(s, d, q, x);
			if(x < ans)
			{
				ans = x;
				ret = i;
			}
		}
	}

	cout << ret + 1 << "\n";
}