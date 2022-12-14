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
  int n;
  cin >> n;
  // if(n==1){
  //   cout<<-1<<endl;
  //   return 0;
  // }
  pii p[n];
  REP(i,n){
    int x,y;
    cin >> x >> y;
    p[i] = make_pair(x,y);
  }
  int w=0,h=0;
  int x=p[0].first,y=p[0].second;
  REPR(i,n){
    int xx = p[i].first, yy = p[i].second;
    if(xx!=x){
      if(w==0)w=xx-x;
      else if(w!=xx-x){
        cout << -1 << endl;
        return 0;
      }
    }
    if(yy!=y){
      if(h==0)h=yy-y;
      else if(h!=yy-y){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  if(w==0 || h==0) cout << -1 << endl;
  else cout << (int)abs(w*h) << endl;
  return 0;
}