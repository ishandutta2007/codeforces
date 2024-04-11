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
int a[1252];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",a+i);
  sort(a,a+n);
  int ans = 0;
  while(true){
    int bef = -1;
    REP(i,n){
      if(a[i]==-1)continue;
      if(bef==-1){
        bef = a[i];
        a[i] = -1;
      }else if(bef<a[i]){
        ++ans;
        bef = a[i];
        a[i] = -1;
      }
    }
    if(bef==-1)break;
  }
  cout<<ans<<endl;
  return 0;
}