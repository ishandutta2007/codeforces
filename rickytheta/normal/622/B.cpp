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
  // input
  int hh,mm;
  scanf("%d:%d",&hh,&mm);
  int a;
  scanf("%d",&a);
  // solve
  int ph = a/60;
  int pm = a%60;
  hh += ph;
  mm += pm;
  while(mm>=60){
    mm -= 60;
    ++hh;
  }
  while(hh>=24){
    hh -= 24;
  }
  printf("%02d:%02d",hh,mm);
  return 0;
}