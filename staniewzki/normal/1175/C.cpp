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

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int t;
	cin >> t;
	REP(_t, t)
	{
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		REP(i, n) cin >> a[i];

		LL best_x = -1;
		auto able = [&](int ans)
		{
			vector<PII> q;
			REP(i, n)
			{
				q.EB(a[i] - ans, 1);
				q.EB(a[i] + ans + 1, -1);
			}

			sort(q.begin(), q.end());
			DB(q);

			int pos = 0;
			int sum = 0;
			while(pos < q.size())
			{
				int x = q[pos].ST;
				while(pos < q.size() && q[pos].ST == x)
				{
					sum += q[pos].ND;
					pos++;
				}
				
				DB(x, sum, pos);
				best_x = x;
				if(sum > k) return true;
			}

			return false;
		};

		int l = 0, r = 1e9;
		while(l < r)
		{
			int m = (l + r) / 2;
			DB(l, m, r);
			if(able(m))
				r = m;
			else
				l = m + 1;
		}

		able(l);
		cout << best_x << "\n";
	}
}