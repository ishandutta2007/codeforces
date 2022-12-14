#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <stdlib.h>
#include <stack>
#include <numeric>
#include <bitset>
#include <cctype>
#include <list>
#include <assert.h>
#include <random>
#include <unordered_map>
#include <ctime>
typedef  long long ll;
using namespace std;
#define INF 2147483647
#define infL (1LL<<60)
#define inf (1<<30)
#define inf9 (1000000000)
#define MOD 1000000007
#define EPS 1e-9
#define Gr 9.8
#define PI acos(-1)
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define REQ(i,n) for(int (i)=1;(i)<=(int)(n);(i)++)
#define lch (rt<<1)
#define rch (rt<<1|1)
#define readmp(n) for(int i=0,u,v;i<n;i++) {scanf("%d%d",&u,&v); mp[u].push_back(v); mp[v].push_back(u);}
typedef pair<int, int> pii;
typedef long double ld;
typedef unsigned int uint;
#define MAX 1005
bool debug = 0;
int n,m,k;
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
string direc="RDLU";
ll ln, lk, lm;
void etp(bool f = 0) {
    puts(f ?"Yes" : "No");
    exit(0);
}
void addmod(int &x, int y, int mod = MOD) {
    assert(y>=0);
    x+=y; if (x>=mod) x-=mod;
    assert(x>=0 && x<mod);
}
void et() {
    puts("-1"); exit(0);
}





int x[MAX],y[MAX],r[MAX];
vector<int> mp[MAX];
vector<pii> vp;
bool vis[MAX];
bool isin(int i,int j) {
    if(i==0) return 1;
    if (r[i] <= r[j]) return 0;
    ll dis = (ll)(x[i]-x[j])*(x[i]-x[j]) + (ll)(y[i]-y[j])*(y[i]-y[j]);
    if (dis <= (ll)(r[i]-r[j])*(r[i]-r[j])) return 1;
    return 0;
}
void add(int x) {
    vis[x]=1;
    REP(i,n) if (!vis[vp[i].second]) {
        if (isin(x, vp[i].second)) {
            mp[x].push_back(vp[i].second);
            add(vp[i].second);
        }
    }
}
ll dp[MAX][3]; // 0-0 1-1 1-0
void dfs(int x) {
    for(int c:mp[x]) {
        dfs(c);
    }
    dp[x][0] += (ll)r[x]*(r[x]);
    for(int c:mp[x]) dp[x][0] += dp[c][2];
    
    dp[x][1] -= (ll)r[x]*(r[x]);
    for(int c:mp[x]) dp[x][1] += dp[c][2];
    
    dp[x][2] += (ll)r[x]*(r[x]);
    for(int c:mp[x]) dp[x][2] += dp[c][1];
    ll tmp = -(ll)r[x]*(r[x]);
    for(int c:mp[x]) tmp += dp[c][0];
    dp[x][2]=max(dp[x][2], tmp);
}
void fmain(int tid) {
    scanf("%d",&n);
    REQ(i,n) scanf("%d%d%d", x+i,y+i,r+i);
    r[0]=inf;
    REQ(i,n) vp.push_back({-r[i], i});
    sort(vp.begin(), vp.end());
    add(0);
    ll ans=0;
    for(int c: mp[0]) {
        dfs(c);
        ans += dp[c][0];
    }
    
    printf("%.10Lf\n", (ld)PI * ans);
}

int main() {
    int t=1;
//    scanf("%d", &t);
    REQ(i,t) {
        fmain(i);
    }
    return 0;
}