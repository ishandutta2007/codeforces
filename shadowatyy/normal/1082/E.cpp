#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define ll long long
#define st f
#define nd s
#define pb PB
#define eb emplace_back
#define mp make_pair
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "

const int N = 5e5+7;

int n, c, ans, ile;

int a[N];
int lewo[N];
int prawo[N];
int ans_lewo[N];
int ans_prawo[N];

void solve(int l, int r)
{
	debug(l, r);

	int m = (l+r)/2;

	if(r-l+1>=2)
	{
		solve(l, m);
		solve(m+1, r);
	}

	int cnt = 0;

	for(int i = m+1; i <= r; ++i)
	{
		if(a[i]==c)
			++cnt;
		else 
		{	
			++prawo[a[i]];
			ans_prawo[a[i]] = max(ans_prawo[a[i]], prawo[a[i]]-cnt);
		}
	}

	cnt = 0;

	for(int i = m; i >= l; --i)
	{
		if(a[i]==c)
			++cnt;
		else
		{
			++lewo[a[i]];
			ans_lewo[a[i]] = max(ans_lewo[a[i]], lewo[a[i]]-cnt);
		}
	}

	for(int i = l; i <= r; ++i)
	{
		ans = max(ans, ile+ans_lewo[a[i]]+ans_prawo[a[i]]);
	}

	for(int i = l; i <= r; ++i)
	{
		lewo[a[i]] = 0;
		prawo[a[i]] = 0;
		ans_lewo[a[i]] = 0;
		ans_prawo[a[i]] = 0;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> c;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		if(a[i]==c)
			++ile;
	}

	ans = ile;
	solve(1, n);

	cout << ans << endl;
}