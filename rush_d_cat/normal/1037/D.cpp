#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 200000+10;

int n, par[N], dis[N], a[N], cnt[N], sum[N], rk[N],u[N],v[N];
struct cmp{
    bool operator() (int a,int b){
        return rk[a]<rk[b];
    }
};
set<int, cmp> g[N];
int main(){
    memset(dis,-1,sizeof(dis));
    scanf("%d", &n);
    for(int i=1;i<n;i++) {
        scanf("%d%d",&u[i],&v[i]);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]); 
        rk[a[i]] = i;
    }
    for(int i=1;i<n;i++) {
        g[u[i]].insert(v[i]);
        g[v[i]].insert(u[i]);
    }

    queue<int> q; q.push(1);
    int las = 0, ok = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        if (a[++las] != u) ok = 0;
        for(auto v: g[u]) {
            q.push(v); g[v].erase(u);
        }
    }
    printf("%s\n", ok?"Yes":"No");
}