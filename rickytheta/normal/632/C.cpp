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

bool le(const string &a, const string &b){
  return a+b < b+a;
}

int main(){
  int n;
  scanf("%d",&n);
  char tmp[52];
  vector<string> vs(n);
  REP(i,n){
    REP(j,52)tmp[j]=0;
    scanf("%s",tmp);
    vs[i] = string(tmp);
  }
  sort(ALL(vs),le);
  REP(i,n)cout<<vs[i];
  cout<<endl;
  return 0;
}