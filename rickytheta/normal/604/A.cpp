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
  int m[5];
  REP(i,5)cin>>m[i];
  int w[5];
  REP(i,5)cin>>w[i];
  int hs,hu;
  cin >> hs >> hu;

  int score[5] = {500,1000,1500,2000,2500};
  int result = 0;
  REP(i,5){
    int s = score[i]*3/10;
    int t = (250-m[i])*score[i]/250 - 50*w[i];
    result += max(s,t);
  }
  result += hs*100 - hu*50;
  cout << result << endl;
  return 0;
}