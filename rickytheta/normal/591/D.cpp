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

P from,to,v,w;
double vmax,twind;

bool calc(double tme){
  P blown;
  if(tme <= twind){
    blown = from + v*tme;
  }else{
    blown = from + v*twind + w*(tme-twind);
  }
  return abs(to-blown) <= vmax*tme;
}

// 
int main(){
  cout.precision(20);
  cout.setf(ios::fixed);
  double x,y;
  cin >> x >> y; from = P(x,y);
  cin >> x >> y; to = P(x,y);
  cin >> vmax >> twind;
  cin >> x >> y; v = P(x,y);
  cin >> x >> y; w = P(x,y);

  double left = 0;
  double right = 1e300;

  REP(_,1e5){
    double mid = (left+right)/2.0;
    bool res = calc(mid);
    if(res) right = mid;
    else left = mid;
  }
  cout << right << endl;
  return 0;
}