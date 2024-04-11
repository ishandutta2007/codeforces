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

int data[125252];
void init(int n){
  REP(i,n)data[i]=-1;
}
int root(int x){
  return data[x]<0?x:data[x]=root(data[x]);
}
void unite(int x,int y){
  x=root(x);y=root(y);
  if(x!=y){
    if(data[x]>data[y])swap(x,y);
    data[x] += data[y];
    data[y] = x;
  }
}

int n;
pii es[125252];
int c[125252];

vi ggg[125252];
set<int> g[125252];
int dist1[125252],dist2[125252];
void dfs(int p,int bef,int d,int *dist){
  dist[p] = d;
  for(int to : g[p])if(to!=bef){
    dfs(to,p,d+1,dist);
  }
}

int main(){
  scanf("%d",&n);
  REP(i,n-1){
    int x,y;
    scanf("%d%d",&x,&y);
    --x;--y;
    es[i] = pii(x,y);
    ggg[x].push_back(y);
    ggg[y].push_back(x);
  }
  REP(i,n)scanf("%d",c+i);
  init(n);
  REP(i,n-1){
    int x = es[i].first, y = es[i].second;
    if(c[x]==c[y])unite(x,y);
  }
  REP(i,n-1){
    int x = root(es[i].first), y = root(es[i].second);
    if(x!=y){
      g[x].insert(y);
      g[y].insert(x);
    }
  }
  REP(i,n)dist1[i]=dist2[i]=-1;
  dfs(root(0),-1,0,dist1);
  int po = max_element(dist1,dist1+n)-dist1;
  dfs(po,-1,0,dist1);
  int yo = max_element(dist1,dist1+n)-dist1;
  dfs(yo,-1,0,dist2);
  int ans = -1;
  REP(i,n){
    int ro = root(i);
    if(dist1[i]>1 || dist2[i]>1)continue;
    int sum = -data[ro];
    for(int to : ggg[i]){
      if(root(to)!=ro)sum+=-data[root(to)];
    }
    if(sum==n)ans=i;
  }
  // REP(i,n)if(dist1[i]!=-1 && dist1[i]<=1 && dist2[i]<=1){
  //   ans = i;
  // }
  if(ans==-1){
    puts("NO");
  }else{
    puts("YES");
    printf("%d\n",ans+1);
  }
  return 0;
}