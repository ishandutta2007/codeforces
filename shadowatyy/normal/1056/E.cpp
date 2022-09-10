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

int P = 31;
int mod1 = 1e9+7;
int mod2 = 1e9+696969;

const int N = 1e6+7;

int n, m, c0, c1;

string s, t;

int h1[N];
int h2[N];

int pot1[N];
int pot2[N];

bool prime(int x)
{
	for(int i = 2; i*i <= x; ++i)
	{
		if(x%i==0)
			return 0;
	}

	return 1;
}

bool equal(int a, int b, int c, int d)
{	
	int v1 = ((h1[b]-h1[a-1]+mod1)*pot1[N-b])%mod1;
	int v2 = ((h1[d]-h1[c-1]+mod1)*pot1[N-d])%mod1;
	int u1 = ((h2[b]-h2[a-1]+mod2)*pot2[N-b])%mod2;
	int u2 = ((h2[d]-h2[c-1]+mod2)*pot2[N-d])%mod2;

	return v1==v2 && u1==u2;
}

bool solve(int len1)
{
	int len0 = (n-len1*c1)/c0;

	if(len0<=0 || len1<=0 || n!=len0*c0+len1*c1)
		return 0;

	int l0 = -1;
	int l1 = -1;
	int ind = 1;

	for(int i = 1; i <= m; ++i)
	{
		if(t[i]=='0')
		{	
			if(l0==-1)
			{
				l0 = ind;
				ind += len0;
				continue;
			}

			if(!equal(l0, l0+len0-1, ind, ind+len0-1))
				return 0;

			l0 = ind;
			ind += len0;
		}
		else
		{
			if(l1==-1)
			{
				l1 = ind;
				ind += len1;
				continue;
			}

			if(!equal(l1, l1+len1-1, ind, ind+len1-1))
				return 0;

			l1 = ind;
			ind += len1;
		}
	}

	if(equal(l1, l1+len1-1, l0, l0+len0-1))
		return 0;

	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	mod1 += rand()%10000;
	mod2 += rand()%10000;

	while(!prime(mod1))
		++mod1;

	while(!prime(mod2))
		++mod2;

	pot1[0] = pot2[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		pot1[i] = pot1[i-1]*P%mod1;
		pot2[i] = pot2[i-1]*P%mod2;
	}

	cin >> t >> s;
	m = t.size();
	n = s.size();
	t = '#' + t;
	s = '#' + s;

	for(int i = 1; i <= m; ++i)
	{
		if(t[i]=='0')
			++c0;
		else
			++c1;
	}

	for(int i = 1; i <= n; ++i)
	{
		h1[i] = s[i]*pot1[i] + h1[i-1];
		h1[i] %= mod1;
		h2[i] = s[i]*pot2[i] + h2[i-1];
		h2[i] %= mod2;
	}

	int ans = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(solve(i))
			++ans;
	}

	cout << ans << endl;
}