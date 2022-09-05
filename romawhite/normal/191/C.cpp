#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=1000000000;

int n, l;
vector<int> g[100005];
vector<int> tin, tout;
int timer;
vector < vector<int> > up;
int d[100005];
void dfs (int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs (to, v);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

map<pair<int,int> , int > vert;

int dp[100005];
bool us[100005];
int res[100005];
int p[100005];

void dfs1(int v){
    us[v] = 1;
    dp[v] = d[v];
    FOR(i,0,g[v].size())
        if (!us[g[v][i]]){
            p[g[v][i]] = v;
            dfs1(g[v][i]);
            dp[v] += dp[g[v][i]];
        }
    if (v)
        res[vert[MP(v,p[v])]] = dp[v];
}

int main(){
    //freopen("INPUT.TXT","r",stdin);
    //freopen("OUT.TXT","w",stdout);
    cin >> n;
    FOR(i,0,n-1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        g[a].PB(b);
        g[b].PB(a);
        vert[MP(a,b)] = i;
        vert[MP(b,a)] = i;
    }
    memset(d,0,sizeof(d));
    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs (0);
    int k;
    cin >> k;
    FOR(i,0,k){
        int a,b;
        cin >> a >> b;
        --a;--b;
        d[a]++;
        d[b]++;
        d[lca(a,b)] -= 2;
    }
    memset(dp,0,sizeof(dp));
    memset(us,0,sizeof(us));
    dfs1(0);
    FOR(i,0,n-1)
        cout << res[i] << ' ';
    return 0;
}