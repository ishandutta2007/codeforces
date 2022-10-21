#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

struct edge{
    int to;
    ll cost;
    edge(int _to, ll _cost){
        to = _to, cost = _cost;
    }
};

int n,m,s,t;
ll k;
vector<edge> G[200500];
ll minC[200500];

priority_queue<P, vector<P>, greater<P> > pque;


int main() {
    cin >> n >> m;
    for(int i= 0; i < m; i++){
        scanf("%d%d%I64d",&s,&t,&k);
        G[s].push_back(edge(t,k));
        G[t].push_back(edge(s,k));
    }
    for(int i = 1; i <= n; i++){
        scanf("%I64d", &minC[i]);
        pque.push(P(minC[i], i));
    }
    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        if(p.first > minC[p.second]) continue;
        for(edge e : G[p.second]){
            if(e.cost * 2 + minC[p.second] < minC[e.to]){
                minC[e.to] = e.cost * 2 + minC[p.second];
                pque.push(P(minC[e.to], e.to));
            }
        }
    }
    for(int i = 1; i <= n; i++){
        printf("%I64d ", minC[i]);
    }
}