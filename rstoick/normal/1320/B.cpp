#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define MAX_V 200005
//lower_bound

struct edge{int to; ll cost;};
typedef pair<ll, int> P;//

int V;
vector<edge> G[MAX_V], H[MAX_V];
ll d[MAX_V];

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d,d+V,LINF);
  d[s] = 0;
  que.push(P(0,s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    rep(i, G[v].size()){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

/*
 * V
 */
int main(void){

  ll n,m;cin>>n>>m;
  V = n;
  rep(i,m){
    int u,v;cin>>u>>v;
    u--;v--;
    G[v].push_back({u, 1});
    H[u].push_back({v, 1});
  }
  int k;cin>>k;
  vector<int> P(k);
  rep(i,k){
    cin>>P[i];P[i]--;
  }
  dijkstra(P.back());
  ll ansP = 0, ansM = 0;
  rep(t,k-1){
    int p = P[t];
    rep(j,H[p].size()){
      int next = H[p][j].to;
      if(d[p] - 1 == d[next] && next != P[t+1]){
        ansP++;
        break;
      }
    }
    int next = P[t+1];
    if(d[p] - 1 != d[next]){
      ansM++;
    }
  }
  cout<<ansM<<" "<<ansP<<endl;
  return 0;
}