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
  int k;
  cin>>k;
  vector<vi> results;
  results.push_back(vi());
  results[0].push_back(0);
  REP(n,k){
    vector<vi> bef = results;
    REP(i,results.size()){
      vi tmp;
      REP(j,results[i].size()){
        tmp.push_back(results[i][j]);
        tmp.push_back(results[i][j]);
      }
      results[i] = tmp;
    }
    if(n==0){
      results.push_back(vi());
      results[1].push_back(1);
      results[1].push_back(0);
    }else{
      REP(i,1<<n){
        vi tmp;
        REP(j,1<<n){
          if(bef[i][j]){
            tmp.push_back(1);
            tmp.push_back(0);
          }else{
            tmp.push_back(0);
            tmp.push_back(1);
          }
        }
        results.push_back(tmp);
      }
    }
  }
  // assert
  // REP(i,1<<k)REP(j,i){
  //   vi a = results[i];
  //   vi b = results[j];
  //   int as = 0;
  //   REP(x,1<<k){
  //     as += (a[x]==b[x])?1:-1;
  //   }
  //   if(as){
  //     DEBUG(i);
  //     DEBUG(j);
  //   }
  // }
  // end
  REP(i,1<<k){
    REP(j,1<<k){
      cout << (results[i][j]==0?'+':'*');
    }
    cout << endl;
  }
  return 0;
}