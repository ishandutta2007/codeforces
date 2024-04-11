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
  ll n;
  cin>>n;
  // 1 to a sequence
  // a*(a+1)/2
  // a*(a+1)/2 < n <= (a+1)*(a+2)/2
  ll left = -1, right = 1e8;
  while(left+1<right){
    ll mid = (left+right)/2;
    ll v = mid*(mid+1)/2;
    if(v>=n)right=mid;
    else left=mid;
  }
  n -= left*(left+1)/2;
  cout<<n<<endl;
  return 0;
}