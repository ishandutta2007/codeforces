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

const int size = 1e5 * 5;
const int LOG = 21;
int jump[size + 1][LOG];

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<PII> p(n);
	REP(i, n)
		cin >> p[i].ST >> p[i].ND;

   	p.EB(-1, -1);
	sort(p.begin(), p.end());

	int mx = -1;
	for(int pos = 0, i = 0; pos <= size; pos++)
	{
		while(i + 1 != p.size() && p[i + 1].ST == pos)
		{
			i++;
			mx = max(mx, p[i].ND);
		}

		jump[pos][0] = (mx < pos ? -1 : mx);
	}

	FOR(j, 1, LOG - 1)
	{
		REP(i, size + 1)
		{
			int last = jump[i][j - 1];
			jump[i][j] = (last == -1 || last == i ? -1 : jump[last][j - 1]);
		}
	}
	
	REP(i, m)
	{
		int l, r;
		cin >> l >> r;
		int ans = 1;

		int pos = l;
		bool ok = false;
		for(int j = LOG - 1; j >= 0; j--)
		{
			if(jump[pos][j] >= r) ok = true;
			else if(jump[pos][j] != -1 && jump[pos][j] != pos)
			{
				ans += (1 << j);
				pos = jump[pos][j];
			}
		}

		if(ok) cout << ans << "\n";
		else cout << -1 << "\n";
	}
}