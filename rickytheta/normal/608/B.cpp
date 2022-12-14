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
  string a,b;
  cin>>a>>b;

  ll cnt1[b.size()], cnt0[b.size()];
  cnt1[0] = (int)(b[0]=='1');
  REPR(i,b.size())cnt1[i] = cnt1[i-1]+(int)(b[i]=='1');
  REP(i,b.size())cnt0[i] = (i+1)-cnt1[i];

  ll sum = 0;
  ll len = b.size()-a.size();
  REP(i,a.size()){
    int d = a[i]-'0';
    if(d==0){
      sum += cnt1[len+i];
      if(i!=0) sum -= cnt1[i-1];
    }else{
      sum += cnt0[len+i];
      if(i!=0) sum -= cnt0[i-1];
    }
  }
  cout << sum << endl;
  return 0;
}