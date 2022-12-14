#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <complex>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
#define REP(i,n) for(int i=0;i<n;++i)
#define REPR(i,n) for(int i=1;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<n;++i)


#define INF 1e9
int n;
int dist[1000][1000];
int cost[1000];
char used[1000];

void dijkstra()
{
  int x, y, mn;
  for(x = 0; x < n; x++){
    cost[x] = INF;
    used[x] = 0;
  }
  cost[0] = 0;
  while(true){
    mn = INF;
    int tx = 0;
    for(x = 0; x < n; x++){
      if(!used[x] && mn > cost[x]){
        mn = cost[x];
        tx = x;
      }
    }
    if(mn == INF)
      break;
    used[tx] = 1;
    for(y = 0; y < n; y++){
      if(cost[y] == mn){
      for(x = 0; x < n; x++){
        if(cost[x] > dist[x][y] + cost[y])
          cost[x] = dist[x][y] + cost[y];
        }
      }
    }
  }
}

int main(){
  cin >> n;
  // broad: i to i+n
  // normal: i to i+1
  REP(i,2*n)REP(j,2*n)dist[i][j]=INF;
  REP(i,n-1){
    int c;
    cin >> c;
    dist[i][i+1]=dist[i+1][i] = c;
  }
  REP(i,n-1){
    int c;
    cin >> c;
    dist[i+n][i+n+1]=dist[i+n+1][i+n] = c;
  }
  n*=2;
  vi result;
  REP(i,n/2){
    int c;
    cin >> c;
    dist[i][i+n/2]=dist[i+n/2][i] = c;
  // REP(k,n){
  //   REP(j,n)cout << (dist[k][j]==INF ? -1 : dist[k][j]) <<" ";
  //   cout<<endl;
  // }
    dijkstra();
    result.push_back(cost[n-1]);
    dist[i][i+n/2]=dist[i+n/2][i] = INF;
  }
  sort(result.begin(),result.end());
  cout << (result[0]+result[1]) << endl;
  return 0;
}