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

const int N = 1e5+7;

int n;

vector<VI> ans;

int t[N];

void zle()
{
	cout << "NO" << endl;
	exit(0);
}

void ok()
{
	cout << "YES" << endl;
	
	cout << ans.size() << endl;
	
	for(auto it:ans)
	{
		cout << it[0] << " " << it[1] << " " << it[2] << endl;
	}
	
	exit(0);
}

void f(int a, int b, int c)
{
	ans.pb({a, b, c});
	t[a] ^= 1;
	t[b] ^= 1;
	t[c] ^= 1;
}

void g(int b, int c)
{
	int r = c-b;
	int a = b-r;
	f(a, b, c);
}	

VI kraw;

int skad[1<<18];
int dist[1<<18];

queue<int> Q;

void brut(int b)
{
	for(int i = 0; i < b; ++i)
	{
		for(int r = 1; i+2*r < b; ++r)
		{
			int m = 0;
			m |= 1<<i;
			m |= 1<<(i+r);
			m |= 1<<(i+2*r);
			kraw.pb(m);
		}
	}
	
	int s = 0;
	
	for(int i = 0; i < b; ++i)
	{
		if(t[i+1])
			s |= 1<<i;
	}
	
	for(int i = 0; i < 1<<b; ++i)
	{
		dist[i] = inf;
	}
	
	dist[s] = 0;
	Q.push(s);
	
	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		
		for(auto it:kraw)
		{
			if(dist[v^it]==inf)
			{
				dist[v^it] = dist[v]+1;
				skad[v^it] = v;
				Q.emplace(v^it);
			}	
		}
	}
	
	if(dist[0]==inf)
		zle();
	
	VI path;
	
	int curr = 0;
	
	while(curr!=s)
	{
		path.eb(curr^skad[curr]);
		curr = skad[curr];
	}
	
	reverse(ALL(path));
	
	for(auto it:path)
	{
		VI foo;
		
		for(int i = 0; i < b; ++i)
		{
			if(it&(1<<i))
				foo.pb(i+1);
		}
		
		f(foo[0], foo[1], foo[2]);
	}
	
	ok();
}

void solve(int b)
{
	if(b<=13)
	{
		brut(b);
		return;
	}
	
	int sum = 0;
	
	for(int i = b-2; i <= b; ++i)
	{
		sum += t[i];
	}
	
	if(sum==3)
	{
		f(b-2, b-1, b);
		solve(b-3);
	}
	else if(sum==0)
		solve(b-3);
	else if(sum==1)
	{
		for(int i = b-2; i <= b; ++i)
		{
			if(t[i])
			{
				f(i-6, i-3, i);
				break;
			}
		}
		
		solve(b-3);
	}
	else
	{
		if(!t[b])
		{
			g(b-2, b-1);
			solve(b-3);
		}
		else if(!t[b-1])
		{
			g(b-2, b);
			solve(b-3);
		}
		else
		{
			VI zap;
		
			for(int i = b-5; i <= b-3; ++i)
			{
				if(t[i])
					zap.pb(i);
			}
			
			if(zap.empty())
			{
				g(b-5, b-1);
				g(b-5, b);
			}
			else if(zap.size()==3)
			{
				g(b-3, b-1);
				g(b-4, b);
			}	 
			else if(zap.size()==2)
			{
				g(zap.back(), b);
				g(zap[zap.size()-2], b-1);			
			}
			else 
			{
				if(zap[0]==b-5)
				{
					f(b-5, b-3, b-1);
					f(b-6, b-3, b);
				}
				else if(zap[0]==b-4)
				{
					f(b-2, b-1, b);
					f(b-6, b-4, b-2);
				}
				else if(zap[0]==b-3)
				{
					f(b-6, b-3, b);
					g(b-6, b-1);
				}
			}
			
			solve(b-6);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];
	}	
	
	solve(n);
	
	for(int i = 1; i <= n; ++i)
	{
		assert(t[i]);
	}
}