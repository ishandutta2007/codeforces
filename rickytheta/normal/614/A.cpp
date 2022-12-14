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

int main(){
  ll l,r,k;
  cin>>l>>r>>k;
  ll bef=0,cur=1;
  while(cur<l && bef == cur/k){
    bef = cur;
    cur *= k;
  }
  bool flag = false;
  while(cur<=r && bef == cur/k){
    if(!flag){
      flag = true;
    }else{
      cout<<" ";
    }
    cout<<cur;
    bef = cur;
    cur *= k;
  }
  if(!flag)cout<<-1;
  cout<<endl;
  return 0;
}