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

double PI = 3.1415926535897932384626;
#define EPS 1e-9

double dot(P a,P b){
  return (conj(a)*b).real();
}
double cross(P a,P b){
  return (conj(a)*b).imag();
}

double dist(P a,P b,P x){
  if(dot(b-a,x-a)<EPS)return abs(x-a);
  if(dot(a-b,x-b)<EPS)return abs(x-b);
  return abs(cross(b-a,x-a))/abs(b-a);
}

int main(){
  int n;
  cin>>n;
  P p;
  int x,y;
  scanf("%d%d",&x,&y);
  p = P(x,y);
  P q[n+1];
  REP(i,n){
    scanf("%d%d",&x,&y);
    q[i]=P(x,y);
  }
  q[n]=q[0];

  double mn = 1e18;
  double mx = 0;
  REP(i,n){
    mn = min(mn,dist(q[i],q[i+1],p));
    mx = max(mx,abs(q[i]-p));
  }
  double result = PI*(mx*mx - mn*mn);
  cout.precision(20);
  cout<<fixed<<result<<endl;
  return 0;
}