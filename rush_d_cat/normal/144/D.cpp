#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
const int NICO = 200000 + 10;
const LL INF = 1e12 + 7;
struct node
{
    LL x, d;
    node() {}
    node(LL a, LL b){x=a;d=b;}
    bool operator < (const node & a) const
    {
        if(d==a.d) return x<a.x;
        return d>a.d;
    }
};
vector<node> edge[NICO];
LL dis[NICO], n, m, s, l;
void dijkstra(LL s)
{
    LL i;
    for(i=0;i<=n;i++) dis[i]=INF;
    dis[s] = 0;
    priority_queue<node> q;
    q.push(node(s,dis[s]));
    while(!q.empty())
    {
        node t1 = q.top(); q.pop();
        for(i=0;i<edge[t1.x].size();i++)
        {
            node t2 = edge[t1.x][i];
            if(dis[t2.x]>t1.d + t2.d) //if
            {
                dis[t2.x] = t1.d + t2.d;
                q.push(node(t2.x, dis[t2.x]));
            }
        }
    }
}

int main()
{
    scanf("%lld %lld %lld", &n, &m, &s);
    for(int i=1;i<=m;i++)
    {
        LL a, b, d;
        scanf("%lld %lld %lld", &a, &b, &d);
        edge[a].push_back(node(b,d));
        edge[b].push_back(node(a,d));
    }
    scanf("%lld", &l);
    dijkstra(s);

    LL ans = 0, add = 0;
    for(LL i = 1; i <= n; i++) {
        for(LL j = 0; j < edge[i].size(); j ++) {
            LL to = edge[i][j].x;
            LL cost = edge[i][j].d;

            if(dis[to] < l) {

                LL need = l - dis[to];
                if(need >= cost) {
                    continue;
                } else
                if(dis[i] + cost - need <= l) {
                    if(dis[i] + cost - need == l) {
                        add ++;
                    }
                    continue;
                } else {
                    ans ++;
                }
            }
        }
    }

    for(LL i = 1; i <= n; i++) {
        if(dis[i] == l) {
            ans ++;
        }
    }
    printf("%lld\n", ans + add / 2);
}