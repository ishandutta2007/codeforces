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

#define N 125252
const int C = 400, B = 300;

// rollback uf
int data[N],unitednum;
pii rec[2521];
int rec_tail;
int recunitednum;
inline void init(int n){REP(i,n)data[i]=-1;unitednum=0;}
inline void snapshot(){rec_tail=0;recunitednum=unitednum;}
inline void rollback(){FORR(i,0,rec_tail)data[rec[i].first]=rec[i].second;unitednum=recunitednum;}
int root(int x){return data[x]<0?x:data[x]=root(data[x]);}
int recroot(int x){
  if(data[x]<0)return x;
  else{
    return recroot(data[x]);
    // rec[rec_tail++] = pii(x,data[x]);
    // return data[x]=recroot(data[x]);
  }
}
void unite(int a,int b){
  a=root(a);b=root(b);
  if(a!=b){
    if(data[a]>data[b])swap(a,b);
    data[a] += data[b];
    data[b] = a;
    unitednum++;
  }
}
int recunite(int a,int b){
  a=recroot(a);b=recroot(b);
  if(a!=b){
    if(data[a]>data[b])swap(a,b);
    rec[rec_tail++] = pii(a,data[a]);
    rec[rec_tail++] = pii(b,data[b]);
    data[a] += data[b];
    data[b] = a;
    unitednum++;
  }
}

int n,k,m,q;
vector<pair<pii,int>> qs[C];
int ans[N];
// 0~4 : i+1 back edge
// 5~9 : i-4 step edge
bitset<10> g[N];

int naive(int l,int r){
  snapshot();
  FOR(i,l,r+1){
    REP(j,5)if(g[i].test(j)&&i-j-1>=l){
      recunite(i,i-j-1);
    }
  }
  int ret = r-l+1 - unitednum;
  rollback();
  return ret;
}

int main(){
  scanf("%d%d%d",&n,&k,&m);
  REP(i,m){
    int u,v;
    scanf("%d%d",&u,&v);
    --u;--v;
    if(u>v)swap(u,v);
    int d = v-u;
    g[u].set(d+4);
    g[v].set(d-1);
  }
  scanf("%d",&q);
  init(n);
  REP(i,q){
    int l,r;
    scanf("%d%d",&l,&r);
    --l;--r;
    if(r-l+1 <= B){
      ans[i] = naive(l,r);
    }else{
      qs[l/B].push_back(make_pair(pii(l,r),i));
    }
  }
  REP(i,C){
    if(qs[i].size()==0)continue;
    sort(ALL(qs[i]),[](pair<pii,int> a, pair<pii,int> b){return a.first.second < b.first.second;});
    int lng = (i+1)*B;
    int rig = (i+1)*B;
    init(n);
    for(auto P : qs[i]){
      int l = P.first.first;
      int r = P.first.second;
      int id = P.second;
      while(rig<=r){
        REP(j,5)if(g[rig].test(j)&&rig-j-1>=lng){
          unite(rig,rig-j-1);
        }
        rig++;
      }
      snapshot();
      FOR(p,l,lng){
        REP(j,5)if(g[p].test(j+5)&&p+j+1<=r){
          recunite(p,p+j+1);
        }
      }
      ans[id] = r-l+1 - unitednum;
      rollback();
    }
  }
  REP(i,q)printf("%d\n",ans[i]);
  return 0;
}