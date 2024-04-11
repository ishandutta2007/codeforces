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

bool used[252][252];

void dfs(int a,int b){
  if(a<0 || b<0)return;
  if(a==0 || b==0){
    used[a][b]=true;
    return;
  }
  if(used[a][b])return;
  used[a][b]=true;
  dfs(a+1,b-2);
  dfs(a-2,b+1);
}

int main(){
  int a,b;
  cin>>a>>b;
  dfs(a,b);
  int ans = 0;
  REP(i,252)REP(j,252){
    if(used[i][j]){
      int x = (a+b)-(i+j);
      ans = max(ans,x);
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}