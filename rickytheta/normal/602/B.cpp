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
  cin >> n;
  vl a(n);
  REP(i,n) cin>>a[i];
  ll result = 1;
  ll nowlen = 1;
  ll nowcntinglen = 1;
  ll nowcnting = a[0];
  ll nowbeforing = -1;
  REPR(i,n){
    if(nowcnting == a[i]){
      ++nowlen;
      ++nowcntinglen;
    }else if(nowbeforing==-1 || nowbeforing==a[i]){
      nowbeforing = a[i];
      swap(nowbeforing,nowcnting);
      nowcntinglen = 1;
      ++nowlen;
    }else{
      nowlen = nowcntinglen + 1;
      nowbeforing = nowcnting;
      nowcnting = a[i];
      nowcntinglen = 1;
    }
    result = max(result,nowlen);
  }
  cout << result << endl;
  return 0;
}