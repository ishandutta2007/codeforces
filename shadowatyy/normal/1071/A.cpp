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
const int nax = 1e6+7;

int a, b;

int juz[nax];

void solve(int x)
{
	debug(I(x), I(a), I(b));

	VI A, B;

	for(int i = min(a, x); i >= 1; --i)
	{
		if(a>=i)
		{
			debug(I(i));
			A.pb(i);
			a -= i;
			i = min(i, a+1);
		}
	}
	
	for(auto it:A)
	{
		juz[it] = 1;
	}
	
	for(int i = 1; i <= x; ++i)
	{
		if(!juz[i])
			B.pb(i);
	}
	
	cout << A.size() << endl;
	
	for(auto it:A)
		cout << it << " ";
		
	cout << endl;
	
	cout << B.size() << endl;
	
	for(auto it:B)
		cout << it << " ";
		
	cout << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> a >> b;
	
	for(int i = 0; i <= a+b; ++i)
	{	
		if(i*(i+1)/2<=a+b && (i+1)*(i+2)/2>a+b)
		{
			solve(i);
			return 0;
		}
	}	
}