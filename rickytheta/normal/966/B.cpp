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

int n,x1,x2;
int c[353531];
pii p[353531];
ll C[353531];
pll mxl[353531], mxr[353531];

int main(){
  scanf("%d%d%d",&n,&x1,&x2);
  REP(i,n)scanf("%d",c+i);
  REP(i,n)p[i] = pii(c[i],i+1);
  sort(p,p+n);
  REP(i,n){
    C[i] = (ll)(n-i)*p[i].first - x2;
    if(C[i]>=0){
      C[i] = C[i] / p[i].first;
    }else{
      C[i] = (C[i] - p[i].first + 1) / p[i].first;
    }
  }
  REP(i,n)mxl[i] = mxr[i] = pll(C[i], i);
  FOR(i,1,n)CHMAX(mxl[i], mxl[i-1]);
  FORR(i,0,n-1)CHMAX(mxr[i], mxr[i+1]);
  int head = 0;
  FORR(l,1,n){
    int min1 = (x1 + l - 1) / l;
    while(head<n && p[head].first<min1)head++;
    if(head==n)break;
    if(head+l>n)continue;
    // right space
    if(head+l<n){
      if(mxr[head+l].first >= 0){
        // ok
        int id = mxr[head+l].second;
        puts("Yes");
        printf("%d %d\n",l,n-id);
        FOR(i,head,head+l)printf("%d%c",p[i].second,i==head+l-1?'\n':' ');
        FOR(i,id,n)printf("%d%c",p[i].second,i==n-1?'\n':' ');
        return 0;
      }
    }
    if(head>0){
      if(mxl[head-1].first >= l){
        // ok
        int id = mxl[head-1].second;
        puts("Yes");
        printf("%d %d\n",l,n-id-l);
        FOR(i,head,head+l)printf("%d%c",p[i].second,i==head+l-1?'\n':' ');
        FOR(i,id,n)if(i<head || head+l<=i)printf("%d%c",p[i].second,i==n-1?'\n':' ');
        return 0;
      }
    }
  }
  puts("No");
  return 0;
}