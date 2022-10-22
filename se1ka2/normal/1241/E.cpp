#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, ll> P;

int u[500003], v[500003];
ll w[500003];
vector<P> g[500003];
int d[500003];
P p[500003];
ll pl[500003], mn[500003];

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) g[i].clear();
        for(int i = 0; i < n - 1; i++){
            scanf("%d %d %lld", &u[i], &v[i], &w[i]);
            u[i]--;
            v[i]--;
            g[u[i]].push_back(P(v[i], w[i]));
            g[v[i]].push_back(P(u[i], w[i]));
        }
        fill(d, d + n, -1);
        queue<int> que;
        d[0] = 0;
        que.push(0);
        while(que.size()){
            int now = que.front();
            que.pop();
            for(P nextp : g[now]){
                int next = nextp.first;
                if(d[next] != -1) continue;
                d[next] = d[now] + 1;
                que.push(next);
            }
        }
        fill(pl, pl + n, 0);
        fill(mn, mn + n, 0);
        for(int i = 0; i < n; i++) p[i] = P(d[i], i);
        sort(p, p + n, greater<P>());
        for(int i = 0; i < n; i++){
            priority_queue<ll> que;
            int now = p[i].second;
            for(P chp : g[now]){
                int ch = chp.first;
                ll cost = chp.second;
                if(d[ch] < d[now]) continue;
                mn[now] += pl[ch];
                if(pl[ch] < mn[ch] + cost) que.push(mn[ch] + cost - pl[ch]);
            }
            for(int i = 0; i < k - 1; i++){
                if(que.empty()) break;
                mn[now] += que.top();
                que.pop();
            }
            pl[now] = mn[now];
            if(!que.empty()) pl[now] += que.top();
        }
        printf("%lld\n", pl[0]);
    }
}