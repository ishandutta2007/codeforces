#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
typedef long long LL;

int n;
LL a[N],c[100];
vector<int> v[N],g[N];

pair<int,int> ban;
set<int> st;
int dis[N];
int bfs(int s,int t){
    queue<int> q;
    for(auto x: st) dis[x]=-1;
    dis[s]=0;
    q.push(s);
    while(q.size()){
        int u=q.front(); q.pop();
        for(auto v: g[u]) {
            if(make_pair(u,v) == ban || make_pair(v,u) == ban) continue;
            if(dis[v]==-1) {
                q.push(v); dis[v]=dis[u]+1;
            }
        }
    }
    return dis[t]==-1?1e9:dis[t];
}
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        for(int j=0;j<62;j++){
            if(a[i]>>j&1) {
                c[j]++;
                v[j].push_back(i);
            }
        }
    }
    for(int j=0;j<62;j++){
        if(c[j]>=3) return !printf("3\n");
    }

    for(int i=0;i<62;i++){
        if(v[i].size()==2) {
            g[v[i][0]].push_back(v[i][1]);
            g[v[i][1]].push_back(v[i][0]);
            st.insert(v[i][0]);
            st.insert(v[i][1]);
        } 
    }   

    int ans = 1e9;
    for(auto u: st) {
        for(auto v: g[u]) {
            ban = make_pair(u,v);
            ans = min(ans, bfs(u,v) + 1);
        }
    }
    if(ans > 1e8) printf("-1\n");
    else printf("%d\n", ans);
}