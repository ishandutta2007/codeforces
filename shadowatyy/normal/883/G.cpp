/* You can't connect the dots looking forward 
   you can only connect them looking backwards. */

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout.precision(10);cout << fixed;
#define dbset(x) for(int i=0 ; i<x.size(); i++) cerr << x[i] << " "; cerr << endl;
#define inf 1000000007
#define INF 1000000000000000000LL
#define PI 3.14159265358979323846
#define mod 1000000007
#define mod1 1000696969
#define flusz fflush(stdout);
#define VI vector<int>
#define VPI vector < pair<int,int> >
#define PII pair<int, int>
#define BIT bitset<N>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORR(x, y, z) for(int x = y; x >= (z); --x)
using namespace std;

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

const int N = 5 * 100*1000;

int test;

int n,m,s;

VI g[N];

vector<pair<int,PII>> G[N];

int cou;

BIT czy;

string S;

int res = 0;

void dfs(int v){
    czy[v] = 1;

    for(auto it:g[v]){
        if (czy[it] == 0){
            dfs(it);
        }
    }

    return;
}

void dfs1(int v){
    czy[v] = 1;
    res++;

    for(auto it:g[v]){
        if (czy[it] == 0){
            dfs1(it);
        }
    }

    for(auto it:G[v]){
        if (czy[it.st] == 0){
            dfs1(it.st);
            // debug(v,it.st,it.nd.st,it.nd.nd);
            if (it.nd.st == 1){
                S[it.nd.nd] = '-';
            }
        }
    }

    return;
}

void solve()
{
    cin >> n >> m >> s;

    FOR(i,1,m){
        int t,a,b;
        cin >> t >> a >> b;

        if (t == 1){ // directed
            g[a].pb(b);
        }else{
            G[a].eb(b,mp(0,cou));
            G[b].eb(a,mp(1,cou));
            cou++;
        }
    }

    czy.reset();

    FOR(i,1,cou){
        S += '+';
    }

    dfs1(s);

    cout << res << endl << S << endl;

    S.clear();
    czy.reset();

    dfs(s);

    res = 0;

    FOR(i,1,cou){
        S += '+';
    }

    FOR(i,1,n){
        if (czy[i] == 1){
            res++;

            for(auto it:G[i]){
                if (it.nd.st == 0){
                    S[it.nd.nd] = '-';
                }
            }
        }
    }

    cout << res << endl << S << endl;

    return;
}

int32_t main()
{
    boost

    test=1;

    while(test--)
    {
        solve();
    }

  return 0;
}