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

	int n;
	cin >> n;

	vector<PII> x(n);
	REP(i, n) cin >> x[i].ST, x[i].ND = i;
	sort(x.begin(), x.end());

	vector<int> s(n), t(n), id(n);
	REP(i, n) s[i] = x[i].ST;
	REP(i, n) id[i] = x[i].ND;

	REP(i, n) cin >> t[i];
	sort(t.begin(), t.end());

	vector<array<int, 3>> ans;
	auto make_move = [&](int i, int j, int d) { ans.EB(array<int, 3>{id[i] + 1, id[j] + 1, d}); };
	vector<PII> open;

	REP(i, n)
	{
		if(s[i] < t[i])	open.EB(t[i] - s[i], i);
		if(s[i] > t[i])
		{
			int d = s[i] - t[i];
			while(d != 0)
			{
				if(open.empty())
				{
					cout << "NO\n";
					return 0;
				}

				PII b = open.back();
				if(b.ST > d)
				{
					make_move(b.ND, i, d);
					open.back().ST -= d;
					d = 0;
				}
				else
				{
					make_move(b.ND, i, b.ST);
					open.pop_back();
					d -= b.ST;
				}
			}
		}
	}

	if(!open.empty())
	{
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n" << ans.size() << "\n";
	for(auto &a : ans)
	{
		for(int v : a)
			cout << v << " ";
		cout << "\n";
	}
}