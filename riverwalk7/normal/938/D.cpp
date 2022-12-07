#include<bits/stdc++.h>
#define int long long
#define MAX 9223372036854775800
#define pii pair<int, int>
#define f first
#define s second
#define mp make_pair
using namespace std;
priority_queue< pii, vector< pii >, greater< pii > > pq;int n, m, dist[200001];vector< pii > adjlist[200001];
signed main() {
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a, b, c;cin>>a>>b>>c;adjlist[a].push_back(mp(b, 2*c));adjlist[b].push_back(mp(a, 2*c));
    }
    for(int i=1;i<=n;i++)
    {
        int p;cin>>p;pq.push(mp(p, i));dist[i]=p;
    }
    while(!pq.empty())
    {
        pii cur=pq.top();int w=cur.f;pq.pop();
        if(dist[cur.s]<w) continue;
        for(auto j:adjlist[cur.s])
        {
            if(dist[j.f]>dist[cur.s]+j.s)
            {
                dist[j.f]=dist[cur.s]+j.s;pq.push(mp(dist[j.f], j.f));
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
    
    return 0;
}