#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

int f(int a,int b){
  return a&b;
}
int g(int a,int b){
  return a^b;
}
int h(int a,int b){
  return a|b;
}

// int f(int a,int b){
//   return a^b;
// }
// int g(int a,int b){
//   return a&b;
// }
// int h(int a,int b){
//   return a|b;
// }

int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int x = g(a,b);
  int y = h(c,d);
  int z = f(b,c);
  int w = g(a,d);
  int s = f(x,y);
  int t = h(z,w);
  int ans = g(s,t);
  cout<<ans<<endl;
  return 0;
}