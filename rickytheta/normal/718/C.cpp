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

void mulmat(ll a[2][2],ll b[2][2],ll o[2][2]){
  ll p[2][2];
  REP(i,2)REP(j,2)p[i][j]=0;
  REP(i,2)REP(j,2)REP(k,2)p[i][j]=(p[i][j]+b[i][k]*a[k][j])%MOD;
  REP(i,2)REP(j,2)o[i][j]=p[i][j];
}
void mulmatvec(ll a[2][2],ll b[2],ll o[2]){
  ll p[2];
  REP(i,2)p[i]=0;
  REP(i,2)REP(j,2)p[i]=(p[i]+a[j][i]*b[j])%MOD;
  REP(i,2)o[i]=p[i];
}
void copymat(ll a[2][2],ll o[2][2]){
  REP(i,2)REP(j,2)o[i][j]=a[i][j];
}

const int MAX = 1<<17;

ll seg[2*MAX][2];
bool lazyflag[2*MAX];
ll lazy[2*MAX][2][2];

void push(int k){
  if(lazyflag[k]){
    mulmatvec(lazy[k],seg[k],seg[k]);
    if(k<MAX-1){
      lazyflag[2*k+1]=true;
      mulmat(lazy[k],lazy[2*k+1],lazy[2*k+1]);
      lazyflag[2*k+2]=true;
      mulmat(lazy[k],lazy[2*k+2],lazy[2*k+2]);
    }
    lazyflag[k]=false;
    lazy[k][0][0]=lazy[k][1][1]=1;
    lazy[k][0][1]=lazy[k][1][0]=0;
  }
}

void mul(int l,int r,ll mat[2][2],int a,int b,int k){
  push(k);
  if(r<=a || b<=l)return;
  if(l<=a && b<=r){
    lazyflag[k]=true;
    copymat(mat,lazy[k]);
    push(k);
  }else{
    int m = (a+b)/2;
    mul(l,r,mat,a,m,2*k+1);
    mul(l,r,mat,m,b,2*k+2);
    seg[k][0]=(seg[2*k+1][0]+seg[2*k+2][0])%MOD;
    seg[k][1]=(seg[2*k+1][1]+seg[2*k+2][1])%MOD;
  }
}
void mul(int l,int r,ll mat[2][2]){
  mul(l,r,mat,0,MAX,0);
}

ll sum(int l,int r,int a,int b,int k){
  push(k);
  if(r<=a || b<=l)return 0ll;
  if(l<=a && b<=r){
    return seg[k][0];
  }else{
    int m = (a+b)/2;
    return (sum(l,r,a,m,2*k+1)+sum(l,r,m,b,2*k+2))%MOD;
  }
}
ll sum(int l,int r){
  return sum(l,r,0,MAX,0);
}

int n,m;

int main(){
  scanf("%d%d",&n,&m);
  ll fibstep[2][2];
  fibstep[0][0]=fibstep[0][1]=fibstep[1][0]=1;
  fibstep[1][1]=0;
  ll unit[2][2];
  unit[0][0]=unit[1][1]=1;
  unit[0][1]=unit[1][0]=0;
  ll beg[2];
  beg[0]=1;beg[1]=0;
  REP(i,n){
    int x;
    scanf("%d",&x);
    ll po[2][2];copymat(fibstep,po);
    ll yo[2][2];copymat(unit,yo);
    int b = x-1;
    while(b>0){
      if(b&1)mulmat(po,yo,yo);
      mulmat(po,po,po);
      b>>=1;
    }
    mulmatvec(yo,beg,seg[i+MAX-1]);
  }
  FORR(i,0,MAX-1){
    int lch=2*i+1,rch=2*i+2;
    REP(j,2)seg[i][j]=(seg[lch][j]+seg[rch][j])%MOD;
  }
  REP(i,2*MAX-1)REP(j,2){
    lazy[i][j][j]=1;
    lazy[i][j][j^1]=0;
  }
  while(m--){
    int q,l,r,x;
    scanf("%d",&q);
    if(q==1){
      scanf("%d%d%d",&l,&r,&x);
      ll po[2][2];copymat(fibstep,po);
      ll yo[2][2];copymat(unit,yo);
      int b = x;
      while(b>0){
        if(b&1)mulmat(po,yo,yo);
        mulmat(po,po,po);
        b>>=1;
      }
      mul(l-1,r,yo);
    }else{
      scanf("%d%d",&l,&r);
      printf("%lld\n",sum(l-1,r));
    }
  }
  return 0;
}