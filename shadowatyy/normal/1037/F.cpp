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

#define int ll
const int mod = 1e9+7;
const int N = 1e6+7;

int n, k, ans;

int a[N];
int lewo[N];
int prawo[N];

int ile_rund(int x)
{
	int l = 0, r = x;

	while(l<r)
	{
		int m = (l+r)/2;

		if(l==m)
			++m;

		if(x-(m-1)*(k-1)>=k)
			l = m;
		else
			r = m-1;
	}

	return l;
}

int zera(int x)
{
	int l = 0, r = x;

	while(l<r)
	{
		int m = (l+r)/2;

		if(l==m)
			++m;

		if(x-m*(k-1)>=0)
			l = m;
		else
			r = m-1;
	}

	return l;
}

int wklad(int l, int p)
{
	int x = 1+l+p;

	int rund = ile_rund(x);

	if(!rund)
		return 0;

	debug(I(rund));

	int raz = x - (k-1);
	int dwa = x - rund*(k-1);
	int len = rund*(raz+dwa)/2;
	debug(I(len));
	int rund_lewo = zera(l);
	int rund_prawo = zera(p);
	l -= k-1;
	p -= k-1;
	int zer = rund_lewo*(2*l - (rund_lewo-1)*(k-1))/2 + rund_prawo*(2*p - (rund_prawo-1)*(k-1))/2;
	return len - zer;
}	

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	a[0] = a[n+1] = inf;

	lewo[1] = 0;

	for(int i = 2; i <= n; ++i)
	{
		int j = i-1;

		while(mp(a[j], j)<mp(a[i], i))
			j = lewo[j];

		lewo[i] = j;
	}

	prawo[n] = n+1;

	for(int i = n-1; i >= 1; --i)
	{
		int j = i+1;

		while(mp(a[j], j)<mp(a[i], i))
			j = prawo[j];

		prawo[i] = j;
	}

	for(int i = 1; i <= n; ++i)
	{	
		int l = i-lewo[i]-1;
		int p = prawo[i]-i-1;

		ans += wklad(l, p)%mod*a[i]%mod;
		ans %= mod;

	//	debug(I(i), I(wklad(l, p)));
	}

	ans %= mod;
	ans += mod;
	ans %= mod;

	cout << ans << endl;
}