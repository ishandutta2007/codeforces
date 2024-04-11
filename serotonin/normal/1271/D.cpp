#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5005;

int n,m,k;
int a[sz],b[sz],c[sz],d[sz];
vector <int> g[sz];

bool vis[sz][sz];
int dp[sz][sz];

int fnc(int army, int pos)
{
    if(pos>n) return 0;
    if(army<a[pos]) return -1;
    if(!vis[army][pos]) {
        vis[army][pos]=1;
        int now=fnc(army+b[pos],pos+1), cnt=0;
        for(int i=0; i<min((int)g[pos].size(), army+b[pos]); i++) {
            cnt+=c[g[pos][i]];
            int get=fnc(army+b[pos]-i-1,pos+1);
            if(get<0) break;
            now=max(now, cnt+get);
        }
        dp[army][pos]=now;
    }
    return dp[army][pos];
}

bool cmp(int x, int y)
{
    return c[x]>c[y];
}

int main()
{
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        d[i]=i;
    }
    while(m--) {
        int u,v;
        scanf("%d %d", &u, &v);
        d[v]=max(d[v],u);
    }
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=n; i++) g[d[i]].push_back(i);
    for(int i=1; i<=n; i++) sort(g[i].begin(), g[i].end(), cmp);
    cout << fnc(k,0);
}