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

int n,m;
int w[252521];
int c[252521];
pii es[252521];
int ssss;

vector<pii> g[252521];
int depth[252521];
int anc[252521][20];
// <w, id>
pii query[252521][20];

// UF
int uf[252521];
int init(int n){
  REP(i,n)uf[i]=-1;
}
int root(int x){
  return uf[x]<0?x:uf[x]=root(uf[x]);
}
void unite(int a,int b){
  a=root(a);b=root(b);
  if(a!=b){
    if(uf[a]>uf[b])swap(a,b);
    uf[a]+=uf[b];
    uf[b]=a;
  }
}
bool same(int a,int b){
  return root(a)==root(b);
}

bool used[252521];
int ans[252521];

int main(){
  scanf("%d%d",&n,&m);
  REP(i,m)scanf("%d",w+i);
  REP(i,m)scanf("%d",c+i);
  REP(i,m){
    int a,b;
    scanf("%d%d",&a,&b);
    es[i] = pii(a-1,b-1);
  }
  scanf("%d",&ssss);

  // create MST
  // set<pii> cs;
  ll costsum = 0ll;
  vector<pii> V(m);
  REP(i,m)V[i] = pii(w[i],i);
  sort(ALL(V));
  init(n);
  REP(i,m){
    int id = V[i].second;
    int a = es[id].first;
    int b = es[id].second;
    if(!same(a,b)){
      unite(a,b);
      g[a].push_back(pii(b,id));
      g[b].push_back(pii(a,id));
      costsum += w[id];
      used[id] = true;
      ans[id] = w[id];
    }
  }

  // prepare for doubling
  const int INF = 1830252521;
  REP(i,n)depth[i]=INF;
  REP(i,n)REP(k,20)anc[i][k]=INF,query[i][k]=pii(INF,INF);
  depth[0] = 0;
  queue<int> Q;
  Q.push(0);
  while(!Q.empty()){
    int pos = Q.front(); Q.pop();
    int d = depth[pos];
    REP(i,g[pos].size()){
      int to = g[pos][i].first;
      int iid = g[pos][i].second;
      if(depth[to]!=INF)continue;
      depth[to] = d+1;
      Q.push(to);
      anc[to][0] = pos;
      query[to][0] = pii(-w[iid],iid);
      int id = 1;
      int cur = pos;
      while(anc[cur][id-1]!=INF){
        int next = anc[cur][id-1];
        anc[to][id] = next;
        query[to][id] = min(query[to][id-1], query[cur][id-1]);
        cur = next;
        ++id;
      }
    }
  }

  ll least = costsum;
  int goodid = -1;
  int goodrem = -1;
  // for any edge
  REP(i,m){
    int s = es[i].first;
    int t = es[i].second;
    // lca & query
    pii QQ = pii(INF,INF);
    int a,b;
    a = s;
    b = t;
    if(depth[a]>depth[b])swap(a,b);
    int diff = depth[b]-depth[a];
    int k = 0;
    while(diff){
      if(diff&1){
        CHMIN(QQ,query[b][k]);
        b = anc[b][k];
      }
      diff>>=1;
      ++k;
    }
    k = 19;
    while(k>=0){
      if(anc[a][k]!=INF && anc[a][k]!=anc[b][k]){
        CHMIN(QQ,query[a][k]);
        CHMIN(QQ,query[b][k]);
        a = anc[a][k];
        b = anc[b][k];
      }
      --k;
    }
    int lca = a;
    if(a!=b){
      CHMIN(QQ,query[a][0]);
      CHMIN(QQ,query[b][0]);
      lca = anc[a][0];
    }
    int remid = QQ.second;
    int addid = i;
    ll cost = costsum;
    cost -= w[remid];
    cost += w[addid];
    cost -= ssss/c[addid];
    if(cost < least){
      least = cost;
      goodid = i;
      goodrem = remid;
    }
  }
  // go
  if(goodid!=-1){
    used[goodrem] = false;
    used[goodid] = true;
    ans[goodid] = w[goodid] - ssss/c[goodid];
  }
  printf("%I64d\n",least);
  REP(i,m){
    if(used[i]){
      printf("%d %d\n",i+1,ans[i]);
    }
  }
  return 0;
}