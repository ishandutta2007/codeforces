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

int n, ans;

map<int, VI> M;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		string s;
		cin >> s;

		int sum = 0, pref = 0;

		for(auto it:s)
		{
			if(it=='(')
				++sum;
			else
				--sum;

			pref = min(pref, sum);
		}

		debug(sum, pref);
		M[sum].pb(pref);
	}

	int cnt0 = 0;

	for(auto it:M[0])
	{
		if(it==0)
			++cnt0;
	}

	ans += cnt0/2;

	for(auto it:M)
	{
		if(it.st<=0)
			continue;

		int ok1 = 0, ok2 = 0;

		for(auto i:it.nd)
		{
			if(i>=0)
				++ok1;
		}

		for(auto i:M[-it.st])
		{
			if(i>=-it.st)
				++ok2;
		}

		debug(it.st, ok1, ok2);
		ans += min(ok1, ok2);
	}

	cout << ans << endl;
}