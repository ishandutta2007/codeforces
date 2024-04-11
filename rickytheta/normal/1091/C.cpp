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

int n;

ll calc(int n, int k){
  ll l = n/k;
  return l*(l-1)/2*k+l;
}

int main(){
  scanf("%d",&n);
  set<ll> f;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      f.insert(calc(n,i));
      if(i*i!=n)f.insert(calc(n,n/i));
    }
  }
  ll last = *f.rbegin();
  for(ll x : f){
    printf("%lld%c",x,x==last ? '\n' : ' ');
  }
  return 0;
}