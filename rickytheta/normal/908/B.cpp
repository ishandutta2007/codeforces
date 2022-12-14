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

int h,w;
char mp[52][52];
char s[125];
int n;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
  scanf("%d%d",&h,&w);
  REP(i,h)scanf("%s",mp[i]);
  scanf("%s",s);
  n = strlen(s);
  int si,sj;
  REP(i,h)REP(j,w)if(mp[i][j]=='S')si=i,sj=j;
  int fo[4] = {0,1,2,3};
  int ans=0;
  do{
    int i = si;
    int j = sj;
    bool ok = false;
    REP(k,n){
      int orde = s[k]-'0';
      int d = fo[orde];
      int ni = i+dy[d];
      int nj = j+dx[d];
      if(ni<0 || nj<0 || ni>=h || nj>=w)break;
      if(mp[ni][nj]=='#')break;
      i=ni;j=nj;
      if(mp[i][j]=='E'){
        ok=true;
        break;
      }
    }
    if(ok)ans++;
  }while(next_permutation(fo,fo+4));
  printf("%d\n",ans);
  return 0;
}