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
  vi a(n);
  REP(i,n)cin>>a[i];

  ll result = 0;
  ll beforeIslandPos = 0;
  ll beforeIslandType = a[0];
  ll subsequenceSeaCount = 0;
  ll beforeType = a[0];
  vi b(n);
  b[0] = a[0];
  b[n-1] = a[n-1];
  REPR(i,n){
    if(i==beforeIslandPos+1 && a[i]==beforeIslandType){
      beforeIslandPos ++;
      b[i] = a[i];
    }else if(a[i]==beforeType){
      subsequenceSeaCount --;
      result = max(result,(subsequenceSeaCount+1)/2);
      if(subsequenceSeaCount%2==1){
        FOR(j,beforeIslandPos,i)b[j]=a[i];
      }else{
        FOR(j,beforeIslandPos,i)b[j]=a[i];
        FOR(j,beforeIslandPos,beforeIslandPos+subsequenceSeaCount/2+1)b[j]=beforeIslandType;
      }
      beforeIslandPos = i;
      beforeIslandType = a[i];
      b[i] = a[i];
      subsequenceSeaCount = 0;
    }else if(i==n-1){
      result = max(result,(subsequenceSeaCount+1)/2);
      if(subsequenceSeaCount%2==1){
        FOR(j,beforeIslandPos,i)b[j]=a[i];
      }else{
        FOR(j,beforeIslandPos,i)b[j]=a[i];
        FOR(j,beforeIslandPos,beforeIslandPos+subsequenceSeaCount/2+1)b[j]=beforeIslandType;
      }
      beforeIslandPos = i;
      beforeIslandType = a[i];
      b[i] = a[i];
      subsequenceSeaCount = 0;
    }else{
      subsequenceSeaCount ++;
    }
    beforeType = a[i];
  }
  cout << result << endl;
  cout << b[0];
  REPR(i,n) cout << " " << b[i];
  cout << endl;
  return 0;
}