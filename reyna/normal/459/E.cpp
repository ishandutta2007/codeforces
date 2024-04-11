//In the name of God
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int Maxn = 4e5;
pair<int,int> Que[Maxn];
int bg,end;
vector<pair<int,pair<int,int> > > edges;
int dp[Maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back(make_pair(w,make_pair(--u,--v)));
    }
    sort(edges.begin(),edges.end());
    for(int i = 0; i < m;i++){
        int u = edges[i].second.first,v = edges[i].second.second,w = edges[i].first;
        if(i && w != edges[i-1].first){
            while(bg != end){
                int nv = Que[bg].first;
                int New = Que[bg].second;
                ++bg;
                dp[nv] = max(dp[nv],New);
            }
        }
        Que[end++] = make_pair(v,dp[u]+1);
    }
    while(bg != end){
        int v = Que[bg].first;
        int New = Que[bg].second;
        ++bg;
        dp[v] = max(dp[v],New);
    }
    int ans = 0;
    for(int i = 0; i < n;i++)
        ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}