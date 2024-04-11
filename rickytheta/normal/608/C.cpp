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

int n;
pii bea[100010];

int calc(int i){
  int ret = 0;
  int exploded = 10000010;
  if(i<0)return exploded;
  if(i!=0) exploded = bea[n-i].first;
  REP(_j,n){
    int j = n-1-_j;
    if(bea[j].first >= exploded){
      ++ret;
    }else{
      exploded = bea[j].first - bea[j].second;
    }
  }
  return ret;
}

int main(){
  cin>>n;
  REP(i,n){
    cin>>bea[i].first>>bea[i].second;
    ++bea[i].first;
  }
  sort(bea,bea+n);

  int iter = 0;
  vl dp(1000010);
  dp[0] = 0;
  ll rest = 0;
  REPR(i,1000010){
    if(bea[iter].first == i){
      dp[i] = dp[max<int>(0,i-bea[iter].second-1)]+1;
      ++iter;
    }else{
      dp[i] = dp[i-1];
    }
    rest = max(rest,dp[i]);
    if(iter==n)break;
  }

  cout << n-rest << endl;
  return 0;
}