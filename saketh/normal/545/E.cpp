#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 300005;

struct edge{
    int u, v, w, i;
};

int N, M, R;
vector<edge> all;
vector<int> adj[MAXN];
ll dist[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        all.push_back({u, v, w, i});
        all.push_back({v, u, w, i});
        adj[u].push_back(2*i);
        adj[v].push_back(2*i+1);
    }
    
    cin >> R;
    R--;

    all.push_back({-1, R, 0, -1});
    memset(dist, 0x7f, sizeof(dist));    
    priority_queue<pair<pair<ll, int> , int>> pq;
    pq.push({{0, 0}, all.size()-1});

    ll tot = 0;
    vector<int> ans;

    while(!pq.empty()){
        ll len = -pq.top().first.first;
        int idx = pq.top().second;
        pq.pop();

        if(len >= dist[all[idx].v]) continue;
        
        dist[all[idx].v] = len;
        tot += all[idx].w;
        if(all[idx].w) ans.push_back(all[idx].i+1);

        for(int en : adj[all[idx].v])
            pq.push({{-(len + all[en].w), -all[en].w}, en});
    }

    cout << tot << endl;
    sort(ans.begin(), ans.end());
    for(int idx : ans)
        cout << idx << " ";
    cout << endl;
}