#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

#define N_MAX 525252
int dist[N_MAX];
vi G[N_MAX];
int tmp[N_MAX];

#define MP make_pair<int,int>

ll calc(int pos){
  int iter = 0;
  stack<pii> S;
  S.push(MP(pos,1));
  while(!S.empty()){
    pii P = S.top(); S.pop();
    int x = P.first, d = P.second;
    dist[x] = d;
    bool flag = true;
    REP(i,G[x].size()){
      int to = G[x][i];
      if(to==0)continue;
      if(dist[to]!=-1)continue;
      flag = false;
      S.push(MP(to,d+1));
    }
    if(flag)tmp[iter++] = d;
  }
  sort(tmp,tmp+iter);
  REPR(i,iter){
    if(tmp[i]<=tmp[i-1])tmp[i]=tmp[i-1]+1;
  }
  return tmp[iter-1];
}

int main(){
  int n;
  scanf("%d",&n);
  REP(i,n-1){
    int a,b;
    scanf("%d%d",&a,&b);
    --a;--b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  REP(i,N_MAX)dist[i] = -1;

  ll res = 0;
  REP(i,G[0].size()){
    ll r = calc(G[0][i]);
    res = max(res,r);
  }
  cout<<res<<endl;
  return 0;
}