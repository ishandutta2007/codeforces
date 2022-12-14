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

const int SZ = 7001;
typedef bitset<SZ> bit;

int n,q;

bool po[SZ];
bit vv[SZ];
bit rv[SZ];
bit ms[100000];

int main(){
  scanf("%d%d",&n,&q);
  FOR(x,1,SZ){
    int tmp = x;
    bool ok = true;
    for(int i=2;i*i<=tmp;i++)if(tmp%i==0){
      tmp/=i;
      if(tmp%i==0)ok = false;
    }
    po[x] = ok;
  }
  FOR(v,1,SZ){
    int it = v;
    while(it < SZ){
      rv[it].set(v);
      if(po[it/v])vv[v].set(it);
      it += v;
    }
  }
  while(q--){
    int typ,x,y,z,v;
    scanf("%d",&typ);
    if(typ==1){
      scanf("%d%d",&x,&v);--x;
      ms[x] = rv[v];
    }else if(typ==2){
      scanf("%d%d%d",&x,&y,&z);--x;--y;--z;
      ms[x] = ms[y] ^ ms[z];
    }else if(typ==3){
      scanf("%d%d%d",&x,&y,&z);--x;--y;--z;
      ms[x] = ms[y] & ms[z];
    }else{
      scanf("%d%d",&x,&v);--x;
      int ans = (ms[x] & vv[v]).count() % 2;
      putchar('0'+ans);
      // puts("");
    }
    // if(typ<4){
    //   DEBUG(x);
    //   DEBUG(ms[x]);
    // }
  }
  puts("");
  return 0;
}