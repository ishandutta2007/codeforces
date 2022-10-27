#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define rd(x) scanf("%d",&x)
#define prt(x) printf("%d\n", x);
#define prtvec(v) for(int i=0;i<v.size();i++) printf("%d%c", v[i], i==(v.size()-1)?'\n':' ');
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,y,x) for(int i=y;i>=x;i--)

const int N=200000+10;
const double EPS = 1e-8;
int n;
LL a[N],deg[N];
vector<int> g[N];
int main(){
    rd(n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            if(a[i]%3==0&&a[i]/3==a[j]) g[i].pb(j), deg[j]++;
            if(a[i]*2==a[j]) g[i].pb(j), deg[j]++;
        }

    queue<int> q;
    for(int i=1;i<=n;i++)
        if(deg[i]==0) q.push(i);
    while(q.size()) {
        int u=q.front(); q.pop();
        printf("%lld ", a[u]);
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            deg[v]--;
            if(deg[v]==0) q.push(v);
        }
    }

}