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
vi children[352521];
int par[352521];
char val[352521];
int dep[352521];
vi depvec[352521];

int main(){
  // n is secret root
  scanf("%d",&n);
  par[0] = n; children[n].push_back(0);
  val[0] = 'Z';
  REP(i,n-1){
    int u,v;char buf[25];
    scanf("%d%d%s",&u,&v,buf);
    --u;--v;
    children[u].push_back(v);
    par[v] = u;
    val[v] = buf[0];
  }
  queue<int> Q;
  Q.push(n);
  dep[n] = 0;
  while(!Q.empty()){
    int p = Q.front(); Q.pop();
    int d = dep[p];
    depvec[d].push_back(p);
    for(int to : children[p]){
      dep[to] = d+1;
      Q.push(to);
    }
  }
  int depmax = *max_element(dep,dep+n);
  int ans = 1252183025;
  int ansp = -1;
  FOR(x,2,depmax+1){
    int ret = n - depvec[x].size();
    typedef pair<int,char> pic;
    map<pic,vi> M;
    // delete x layer
    for(int p : depvec[x]){
      int yo = par[p];
      for(int to : children[p]){
        pic po = pic(yo,val[to]);
        M[po].push_back(to);
      }
    }
    while(M.size()){
      map<pic,vi> M2;
      for(auto P : M){
        pic po = P.first;
        vi V = P.second;
        if(V.size()==1)continue;
        // printf("%d %c %d\n",po.first,po.second,V.size());
        ret -= V.size()-1;
        int daihyo = V[0];
        for(int p : V){
          for(int to : children[p]){
            pic poyo = pic(daihyo,val[to]);
            M2[poyo].push_back(to);
          }
        }
      }
      swap(M,M2);
    }
    if(ret < ans){
      ans = ret;
      ansp = x;
    }
    // DEBUG(x);
    // DEBUG(ret);
  }
  printf("%d\n%d\n",ans,ansp-1);
  return 0;
}