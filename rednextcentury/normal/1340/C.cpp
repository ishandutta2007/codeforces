#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
ll dist[10001][1001];
int n,m;
ll g,r;
void bfs(){
    int v = 0, curT = 0;
    deque<pair<int,int> > q;
    for (int i=0;i<m;i++) for (int j=0;j<g;j++) dist[i][j] = 2e7;
    dist[0][0]=0;
    q.push_front({0,0});
    while(!q.empty()){
        auto p = q.front(); q.pop_front();
        v = p.first;
        curT = p.second;
        if (v){
            int L = a[v] - a[v-1];
            if (curT + L <= g){
                int newT = curT+L;
                int cost = 0;
                if (newT>=g) newT = 0, cost=1;
                
                if (dist[v-1][newT] > dist[v][curT] + cost){
                    dist[v-1][newT] = dist[v][curT] + cost;
                    if (cost==0) q.push_front({v-1, newT});
                    else q.push_back({v-1, newT});
                }
            }
        }
        if (v+1<m){
            int L = a[v+1] - a[v];
            if (curT + L <= g){
                int newT = curT+L;
                int cost = 0;
                if (newT>=g) newT = 0, cost=1;
                
                if (dist[v+1][newT] > dist[v][curT] + cost){
                    dist[v+1][newT] = dist[v][curT] + cost;
                    if (cost==0) q.push_front({v+1, newT});
                    else q.push_back({v+1, newT});
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<m;i++)
        cin>>a[i];
    sort(a,a+m);
    cin>>g>>r;
    bfs();
    ll ret = dist[m-1][0]*(r+g) - r;
    for (int i=1;i<g;i++) ret=min(ret, dist[m-1][i]*(r+g)+i);
    if (ret>=2e7)
        ret=-1;
    cout<<ret<<endl;
}