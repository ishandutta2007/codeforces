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

const int N = 1e6+7;
const int nax = 5007;

int q, cnt;

int sito[N];

map<VI, int> nr;

ll dziel[nax];
int dist[nax][nax];

VI G[nax];

queue<PII> Q;

int min_dep[nax];

VI get(int x)
{
	VI ans;
	
	int last = -1;
	
	while(sito[x])
	{
		if(last==sito[x])
			ans.back()++;
		else
			ans.pb(1);
			
		last = sito[x];
		x /= sito[x];
	}
	
	sort(ALL(ans));
	return ans;
}

void znajdz_kraw(VI fact, int v)
{
	VI nowy = fact;
	nowy.pb(1);
	sort(ALL(nowy));
	
	if(nr.count(nowy))
		G[v].pb(nr[nowy]);
	
	for(int i = 0; i < fact.size(); ++i)
	{
		if(fact[i]>1)
		{
			nowy = fact;
			--nowy[i];
			sort(ALL(nowy));
			
			if(nr.count(nowy))
				G[v].pb(nr[nowy]);
		}
		else
		{
			nowy = fact;
			swap(nowy[i], nowy.back());
			nowy.pop_back();
			sort(ALL(nowy));
			
			if(nr.count(nowy))
				G[v].pb(nr[nowy]);
		}
		
		nowy = fact;
		++nowy[i];
		sort(ALL(nowy));
		
		if(nr.count(nowy))
			G[v].pb(nr[nowy]);
	}
	
	sort(ALL(G[v]));
	G[v].erase(unique(ALL(G[v])), G[v].end());
}	

void generuj(VI fact, int dep)
{
	if(dep>2 || dep>=min_dep[nr[fact]])
		return;
		
	min_dep[nr[fact]] = dep;
		
	VI nowy = fact;
	nowy.pb(1);
	sort(ALL(nowy));
	
	if(!nr.count(nowy))
	{
		nr[nowy] = ++cnt;
		min_dep[cnt] = inf;
	}
	
	generuj(nowy, dep+1);
	
	for(int i = 0; i < fact.size(); ++i)
	{	
		nowy = fact;
		++nowy[i];
		sort(ALL(nowy));
		
		if(!nr.count(nowy))
		{
			nr[nowy] = ++cnt;
			min_dep[cnt] = inf;
		}
		
		generuj(nowy, dep+1);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	for(int i = 2; i < N; ++i)
	{
		if(!sito[i])
		{
			for(int j = i; j < N; j += i)
			{
				sito[j] = i;
			}
		}	
	}
	
	for(int i = 1; i < N; ++i)
	{
		VI fact = get(i);
		
		if(!nr[fact])
		{
			nr[fact] = ++cnt;
			min_dep[cnt] = inf;
		}
		
		generuj(fact, 0);
	}
	
	
	debug(cnt);
	cerr << cnt << endl;
	
	for(auto it:nr)
	{
		ll ile = 1;
		
		for(auto e:it.st)
			ile *= e+1;
			
		dziel[it.nd] = ile;
	}
	
	for(auto it:nr)
	{
		znajdz_kraw(it.st, it.nd);
	}
	
	for(int i = 1; i <= cnt; ++i)
	{
		for(int j = 1; j <= cnt; ++j)
		{
			if(dziel[i]==dziel[j])
			{
				dist[i][j] = 0;
				Q.emplace(i, j);
			}
			else
				dist[i][j] = inf;
		}	
	}
	
	while(!Q.empty())
	{
		int a = Q.front().st;
		int b = Q.front().nd;
		Q.pop();
		
		for(auto it:G[a])
		{
			if(dist[it][b]==inf)
			{
				dist[it][b] = dist[a][b]+1;
				Q.emplace(it, b);
			}
		}
		
		for(auto it:G[b])
		{
			if(dist[a][it]==inf)
			{
				dist[a][it] = dist[a][b]+1;
				Q.emplace(a, it);
			}
		}
	}
	
	/*int checksum = 0;
	
	for(int i = 1; i <= cnt; ++i)
	{
		if(min_dep[i])
			continue;	

		for(int j = 1; j <= cnt; ++j)
		{
			if(min_dep[j])
				continue;
				
			checksum += dist[i][j];
		}
	}
	
	cerr << checksum << endl;*/
	
	cin >> q;
	
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		
		VI fa = get(a);
		VI fb = get(b);
		
		cout << dist[nr[fa]][nr[fb]] << endl;
	}
}