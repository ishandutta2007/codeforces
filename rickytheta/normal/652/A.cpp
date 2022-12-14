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
  int f,g,a,b;
  scanf("%d%d%d%d",&f,&g,&a,&b);
  int now = f;
  int cnt = 0;
  now += a*8;
  if(now>=g){
    printf("0\n");
    return 0;
  }else if(a<=b){
    printf("-1\n");
    return 0;
  }
  ++cnt;
  while(true){
    now += (a-b)*12;
    if(now>=g){
      printf("%d\n",cnt);
      break;
    }
    ++cnt;
  }
  return 0;
}