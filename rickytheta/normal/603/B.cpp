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

bool used[1000010];

int main(){
  ll p,k;
  cin >> p >> k;
  assert(3<=p && p<=1e6);
  assert(0<=k && k<=p-1);
  assert(p%2==1);
  // assert p is prime

  // f(kx%p)%p = kf(x)%p
  // f: {0...p}->{0...p}

  ll result = 1;
  if(k==1)result = p;
  used[0] = true;
  ll iter = 0;
  while(true){
    while(iter<p && used[iter])++iter;
    if(iter==p)break;
    ll x = iter;
    result *= p;
    result %= MOD;
    while(!used[x]){
      used[x] = true;
      x *= k;
      x %= p;
    }
  }

  cout << result << endl;

  return 0;
}