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

int n,w,h;
typedef pair<pii,int> piii;
vector<piii> xs;
vector<piii> ys_;
vi ys[252521];
queue<int> ids[252521];
const int C = 112521;

int ansx[125252], ansy[125252];

int main(){
  scanf("%d%d%d",&n,&w,&h);
  // swap(w,h);
  REP(i,n){
    int g,p,t;
    scanf("%d%d%d",&g,&p,&t);
    // g = 3-g;
    if(g==1){
      xs.push_back(piii(pii(p,t),i));
    }else{
      ys_.push_back(piii(pii(p,t),i));
    }
  }
  sort(ALL(ys_));
  reverse(ALL(ys_));
  REP(i,ys_.size()){
    int y = ys_[i].first.first;
    int t = ys_[i].first.second;
    int id = ys_[i].second;
    ys[y-t+C].push_back(y);
    ids[y-t+C].push(id);
  }
  sort(ALL(xs));
  REP(i,xs.size()){
    int x = xs[i].first.first;
    int t = xs[i].first.second;
    int id = xs[i].second;
    if(ids[x-t+C].size()){
      int nid = ids[x-t+C].front();
      ids[x-t+C].pop();
      ids[x-t+C].push(id);
      id = nid;
    }
    ansx[id] = x;
    ansy[id] = h;
  }
  REP(ytc,252521){
    REP(i,ys[ytc].size()){
      int y = ys[ytc][i];
      int id = ids[ytc].front(); ids[ytc].pop();
      ansx[id] = w;
      ansy[id] = y;
    }
  }
  REP(i,n)printf("%d %d\n",ansx[i],ansy[i]);
  return 0;
}