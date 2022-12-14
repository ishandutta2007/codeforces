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

int n;
int a[125252],b[125252],c[125252];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d%d%d",a+i,b+i,c+i);
  // single
  int maxR2 = -1;
  int singleWin = -1;
  REP(i,n){
    int R2 = min({a[i],b[i],c[i]});
    if(R2 > maxR2){
      maxR2 = R2;
      singleWin = i;
    }
  }
  // double
  map<pii,vector<pii>> M;
  REP(i,n){
    map<pii,int> UM;
    vi k(3);
    k[0]=a[i];
    k[1]=b[i];
    k[2]=c[i];
    sort(ALL(k));
    CHMAX(UM[pii(k[0],k[1])],k[2]);
    CHMAX(UM[pii(k[1],k[2])],k[0]);
    CHMAX(UM[pii(k[0],k[2])],k[1]);
    for(auto P:UM){
      pii x = P.first;
      int y = P.second;
      M[x].push_back(pii(y,i));
    }
  }
  bool dwinflag = false;
  int da,db;
  for(auto P:M){
    pii xy = P.first;
    int x = xy.first;
    int y = xy.second;
    vector<pii> V = P.second;
    if(V.size()==1)continue;
    sort(ALL(V));
    reverse(ALL(V));
    int z = V[0].first+V[1].first;
    int R2 = min({x,y,z});
    if(R2 > maxR2){
      dwinflag = true;
      da = V[0].second;
      db = V[1].second;
    }
  }
  if(dwinflag){
    puts("2");
    printf("%d %d\n",da+1,db+1);
  }else{
    puts("1");
    printf("%d\n",singleWin+1);
  }
  return 0;
}