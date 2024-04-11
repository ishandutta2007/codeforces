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
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

pii operator+(const pii &a,const pii &b){
  return pii(a.first+b.first,a.second+b.second);
}
pii operator-(const pii &a,const pii &b){
  return pii(a.first-b.first,a.second-b.second);
}
ll cross(const pii &a,const pii &b){
  return (ll)a.first*b.second - (ll)a.second*b.first;
}
ll tri(const pii &a,const pii &b,const pii &c){
  return abs(cross(b-a,c-a));
}

int n;
ll s;
pii ps[5252];
pii ch[5252];
int iter;

bool deb = false;

int main(){
  scanf("%d%I64d",&n,&s);
  REP(i,n){
    int x,y;
    scanf("%d%d",&x,&y);
    ps[i] = pii(x,y);
  }
  deb = n==5000;
  deb = false;
  sort(ps,ps+n);
  sort(ps+1,ps+n,[](const pii &a,const pii &b){
    return cross(a-ps[0],b-ps[0])>0;
  });
  ch[0] = ps[0];
  iter = 1;
  FOR(i,1,n){
    while(iter>=2){
      if(cross(ps[i]-ch[iter-2],ch[iter-1]-ch[iter-2])>0)--iter;
      else break;
    }
    ch[iter++] = ps[i];
  }
  n = iter;
  if(deb)DEBUG(n);
  ll mxval = 0;
  int ansa,ansb,ansc;
  ansa=ansb=ansc=0;
  REP(i,n){
    int a = i;
    int c = i+2;
    FOR(b,i+1,i+n-1){
      while(c<i+n-1){
        if(tri(ch[a%n],ch[b%n],ch[c%n])<tri(ch[a%n],ch[b%n],ch[(c+1)%n])) c++;
        else break;
      }
      ll val = tri(ch[a%n],ch[b%n],ch[c%n]);
      if(mxval < val){
        mxval = val;
        ansa = a;
        ansb = b;
        ansc = c;
      }
    }
  }
  if(deb)DEBUG(mxval/2);
  ansa %= n;
  ansb %= n;
  ansc %= n;
  pii a,b,c;
  a = ch[ansa];
  b = ch[ansb];
  c = ch[ansc];
  if(deb){
    printf("%d %d\n",a.first,a.second);
    printf("%d %d\n",b.first,b.second);
    printf("%d %d\n",c.first,c.second);
  }
  pii x,y,z;
  x = c-(a-b);
  y = a-(b-c);
  z = b-(c-a);
  printf("%d %d\n",x.first,x.second);
  printf("%d %d\n",y.first,y.second);
  printf("%d %d\n",z.first,z.second);
  return 0;
}