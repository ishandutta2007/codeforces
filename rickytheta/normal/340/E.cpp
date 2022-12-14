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

ll modpow(ll a, ll b){
  ll r = 1;
  while(b){
    if(b&1)r=r*a%MOD;
    a=a*a%MOD;
    b>>=1;
  }
  return r;
}
ll modinv(ll a){return modpow(a,MOD-2);}

int n;
int a[2521];

bool ex[2521];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",a+i);
  REP(i,n)a[i] = a[i]==-1 ? -1 : a[i]-1;
  // a[x]!=-1 && !(x in a) -> x can be place anywhere
  // a[x]==-1 &&   x in a  -> anything can be place at a[x]
  // a[x]!=-1 &&   x in a  -> x is done
  // a[x]==-1 && !(x in a) -> x cannot be place at a[x]
  REP(i,n)if(a[i]!=-1)ex[a[i]]=true;
  int m = 0, k = 0;
  REP(i,n){
    if(ex[i])continue;
    m++;
    if(a[i]==-1)k++;
  }
  // permutation m
  // k items cannot place at id
  ll ans = 0;
  REP(i,k+1){
    ll comb = 0;
    { // k C i
      ll a = 1, b = 1;
      FOR(j,1,i+1){
        a = a*(k-j+1)%MOD;
        b = b*j%MOD;
      }
      comb = a * modinv(b) % MOD;
    }
    ll fact = 1;
    FOR(j,1,m-i+1)fact=fact*j%MOD;
    int sign = i%2==0 ? 1 : -1;
    ans += MOD + sign*comb*fact%MOD;
    ans %= MOD;
  }
  printf("%lld\n",ans);
  return 0;
}