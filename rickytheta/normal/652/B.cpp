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

int a[1252];
int res[1252];

int main(){
  int n;
  scanf("%d",&n);
  REP(i,n) scanf("%d",a+i);
  sort(a,a+n);
  int x = (n+1)/2;
  REP(i,x){
    res[2*i] = a[i];
  }
  REP(i,n-x){
    res[2*i+1] = a[n-1-i];
  }
  printf("%d",res[0]);
  REPR(i,n)printf(" %d",res[i]);
  printf("\n");
  return 0;
}