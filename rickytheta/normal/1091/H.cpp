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

#define SZ 200025
#define MX 1025
typedef bitset<SZ> bit;

int n,f;
bool prime[SZ];
int lastprime[SZ];
bool semiprime[SZ];
int gr[SZ];
bit msk;
bit bb[MX];

int main(){
  scanf("%d%d",&n,&f);
  fill(prime, prime+SZ, true);
  prime[0] = prime[1] = false;
  lastprime[0] = lastprime[1] = 1;
  FOR(i,2,SZ)if(prime[i]){
    lastprime[i] = i;
    int it = i+i;
    while(it<SZ){
      prime[it] = false;
      lastprime[it] = i;
      it += i;
    }
  }
  REP(i,SZ){
    semiprime[i] = prime[i] || prime[i/lastprime[i]];
  }
  REP(i,SZ)if(semiprime[i] && i!=f)msk.set(i);
  FOR(i,1,SZ){
    int g = 0;
    while(true){
      if(bb[g].test(i))g++;
      else break;
    }
    gr[i] = g;
    bb[g] |= (msk<<i);
  }
  int ans = 0;
  REP(i,n){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    ans ^= gr[c-b] ^ gr[b-a];
  }
  puts(ans==0 ? "Bob" : "Alice");
  puts(ans!=0 ? "Bob" : "Alice");
  return 0;
}