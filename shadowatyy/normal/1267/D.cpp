#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define LL long long
#define LD long double
#define VPII vector<PII>
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
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
#define siz(c) SIZ(c)
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

#define I(x) #x " =", (x), " "

const int N = 307;

int n;

int biore[N];
int daje[N];
int ok[N];
int taki[8][8];
int taki_biore[8];
int mam[8];
int ucinam[N];

VPII ans;

VI jedynki = {1, 2, 4};
VI dwojki = {1+2, 1+4, 2+4};

int32_t main()
{
    cin >> n;
    
    for(int i = 1; i <= n; ++i)
    {
        int maska = 0;
        
        for(int j = 0; j < 3; ++j)
        {
            int x;
            cin >> x;
            maska += (1<<j)*x;
        }   
        
        biore[i] = maska;
        
        if(!biore[i])
        	ok[i] = 1;
    }
    
    for(int i = 1; i <= n; ++i)
    {
        int maska = 0;
        
        for(int j = 0; j < 3; ++j)
        {
            int x;
            cin >> x;
            maska += (1<<j)*x;
        }   
        
        daje[i] = maska;
        daje[i] &= biore[i];
        taki[biore[i]][daje[i]] = i;
        taki_biore[biore[i]] = i;
    }
    
    ok[1] = 1;
    mam[7] = 1;
    
    for(int i = 2; i <= n; ++i)
    {
        if(biore[i]==7)
        {
        	ans.eb(1, i);
        	ucinam[i] = 1;
        	mam[daje[i]] = i;
        	ok[i] = 1;
        }
    }
    
    for(auto jed:jedynki)
    {
		if(mam[jed])
			continue;
			
		for(auto dwa:dwojki)
		{
			if((dwa&jed) && mam[dwa] && taki[dwa][jed])
			{
				ans.eb(mam[dwa], taki[dwa][jed]);
				ok[taki[dwa][jed]] = 1;
				mam[jed] = taki[dwa][jed];
				ucinam[taki[dwa][jed]] = 1;
			}
		}
	}
	
	for(auto dwa:dwojki)
	{
		if(mam[dwa] || !taki_biore[dwa])
			continue;
	
		VI vec;
		
		for(auto jed:jedynki)
		{
			if(dwa&jed)
				vec.pb(jed);
		}
		
		if(mam[vec[0]] && mam[vec[1]])
		{
			ans.eb(mam[vec[0]], taki_biore[dwa]);
			ans.eb(mam[vec[1]], taki_biore[dwa]);
			ok[taki_biore[dwa]] = 1;
			mam[dwa] = taki_biore[dwa];
		}
	}
	
	for(int i = 1; i <= n; ++i)
	{
		if(!ok[i])
		{
			if(!mam[biore[i]])
			{
				cout << "Impossible" << endl;
				return 0;
			}
			
			ans.eb(mam[biore[i]], i);
		}
	}
	
	cout << "Possible" << endl;
	
	for(int i = 1; i <= n; ++i)
	{
		cout << ucinam[i] << " ";
	}
	
	cout << endl;
	
	cout << siz(ans) << endl;
	
	for(auto it:ans)
		cout << it.st << " " << it.nd << endl;
}