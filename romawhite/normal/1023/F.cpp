#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
#include <assert.h>
#include <complex.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define FILL(A,val) memset(A,val,sizeof(A))

#define ALL(V) V.begin(),V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double Pi = acos(-1.0);
const int INF = 1000000000;
const Int INF2 = Int(INF) * 5000;
const Int INF3 = Int(INF) * INF;
const int MAX = 500007;
const int MAXE = 2007000;
const int MAXV = 5000;
const int BASE = 1000000000;
const int ST = 1000000007;

const int MOD = 1000000007;

int p[MAX];
int get(int v)
{
    if (p[v] == v)return v;
    return p[v] = get(p[v]);
}

bool Union(int a , int b)
{
    a = get(a);
    b = get(b);
    if (a == b) return false;
    
    p[b] = a;
    return true;
}


vector<PII> G[MAX];

vector<pair<int, PII> > Q;

int tin[MAX];
int tout[MAX];
int timer = 0;
int up[MAX][20];

void dfs_lca(int v, int p)
{
    up[v][0] = p;
    FOR(i,1,20)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    
    tin[v] = timer ++;
    
    FOR(i,0,SZ(G[v]))
    {
        int to = G[v][i].first;
        if (to == p) continue;
        
        dfs_lca(to, v);
        
    }
    
    tout[v] = timer ++;
}

bool upper(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b)
{
    if (upper(a , b)) return a;
    if (upper(b, a)) return b;
    
    RFOR(i,20,0)
    {
        if (!upper(up[a][i], b))
            a = up[a][i];
    }
    return up[a][0];
}

VI Add[MAX];
// 2 times del
VI Del[MAX];

multiset<int> S[MAX];

Int res = 0;
bool ok = true;

void dfs(int v, int p)
{
    int up_cost = 47;
    
    FOR(i,0,SZ(G[v]))
    {
        int to = G[v][i].first;
        if (to == p)
        {
            up_cost = G[v][i].second;
            continue;
        }
        dfs(to, v);
        
        if (SZ(S[to]) > SZ(S[v]))
        {
            S[v].swap(S[to]);
        }
        
        for(auto it = S[to].begin(); it != S[to].end(); ++it)
            S[v].insert(*it);
        
        {
            multiset<int> temp;
            temp.swap(S[to]);
        }
        
    }
    
    FOR(i,0,SZ(Add[v]))
    {
        S[v].insert(Add[v][i]);
    }
    FOR(i,0,SZ(Del[v]))
    {
        S[v].erase(S[v].find(Del[v][i]));
        S[v].erase(S[v].find(Del[v][i]));
    }
    
    if (up_cost == 0)
    {
        
        if (SZ(S[v]) == 0)
        {
            ok = false;
        }
        else
        {
            res += *S[v].begin();
        }
    }
    
}
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt" , "w", stdout);
    
    
    
    int n , k , m;
    cin >> n >> k >> m;
//    n = 500000;
//    k = n - 1;
//    m = 500000;
    
    
    FOR(i,0,n)
        p[i] = i;
    
    vector<pair<int, PII> > E;
    
    FOR(i,0,k)
    {
        int a , b;
        scanf("%d%d" , &a , &b);
//        a = i + 1;
//        b = i / 2;
        --a;--b;
        
        E.push_back(MP(0, MP(a , b)));
    }
    
    FOR(i,0,m)
    {
        int a , b , w;
        scanf("%d%d%d" , &a , &b, &w);
//        a = 1;
//        b = n;
//        w = rand() % INF + 1;
        --a;--b;
        
        E.push_back(MP(w , MP(a , b)));
    }
    
    FOR(i,0,SZ(E))
    {
        int a = E[i].second.first;
        int b = E[i].second.second;
        
        if (Union(a, b))
        {
            G[a].push_back(MP(b, E[i].first));
            G[b].push_back(MP(a , E[i].first));
        }
        else
        {
            Q.push_back(E[i]);
        }
    }

    dfs_lca(0, 0);
    
    FOR(i,0,SZ(Q))
    {
        int a = Q[i].second.first;
        int b = Q[i].second.second;
        
        int c = lca(a , b);
        
        Add[a].push_back(Q[i].first);
        Add[b].push_back(Q[i].first);
        Del[c].push_back(Q[i].first);
    }
    
    dfs(0, -1);
    
    if (!ok) cout << -1 << endl;
    else cout << res << endl;
    
        
}