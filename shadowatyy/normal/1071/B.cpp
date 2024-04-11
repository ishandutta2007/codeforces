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

const int N = 2007;

int n, k;

char t[N][N];
PII skad[N][N];
int dp[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n >> k;
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			cin >> t[i][j];
		}	
	}
	
	for(int i = 0; i <= n+1; ++i)
	{
		for(int j = 0; j <= n+1; ++j)
		{
			dp[i][j] = inf;
		}
	}
	
	if(t[1][1]=='a')	
		dp[1][1] = 0;
	else if(k>0)
		dp[1][1] = 1;
	else
		dp[1][1] = 0;
		
	for(int d = 3; d <= 2*n; ++d)
	{
		char best = 'z'+1;
	
		for(int y = 1; y <= n; ++y)
		{
			int x = d-y;
			
			if(x<1 || x>n)
				continue;
				
			if(dp[y-1][x]<k || dp[y][x-1]<k)
				best = 'a';
			else if(dp[y-1][x]<=k || dp[y][x-1]<=k)
				best = min(best, t[y][x]);
		}	
		
		for(int y = 1; y <= n; ++y)
		{
			int x = d-y;
			
			if(x<1 || x>n)
				continue;	
			
			if(dp[y-1][x]<dp[y][x-1])
			{
				dp[y][x] = dp[y-1][x];
				skad[y][x] = mp(y-1, x);
			}	
			else
			{
				dp[y][x] = dp[y][x-1];
				skad[y][x] = mp(y, x-1);
			}
			
			if(t[y][x]!=best)
				++dp[y][x];
		}
	}
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			debug(dp[i][j]);
		}
	}
	
	string ans;
	
	int y = n, x = n;
	
	while(x+y>2)
	{
		debug(I(y), I(x));
		ans += t[y][x];
		
		if(skad[y][x]==mp(y-1, x))
			--y;
		else
			--x;
	}	
	
	ans += t[y][x];
	
	reverse(ALL(ans));
	
	for(int i = 0; i < ans.size(); ++i)
	{
		if(k>0 && ans[i]!='a')
		{	
			ans[i] = 'a';
			--k;
		}
	}
	
	cout << ans << endl;
}