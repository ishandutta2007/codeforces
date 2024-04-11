#define NDEBUG
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;
const int w1=700,w2=350;
int n,m,x,y,a[300001],l[300001],r[300001],cnt,v[600001];
int val[300001],c,ans[300001];
int lt,rt;
vector<int> to[300001];
namespace io {
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
  inline char getc () {return (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++);}
  inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
  inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
  template<class T>
  inline void read(T &x) {
    char ch; int f = 1;
    x = 0;
    while(isspace(ch = getc()));
    if(ch == '-') ch = getc(), f = -1;
    do x = x * 10 + ch - '0'; while(isdigit(ch = getc()));
    x *= f;
  }
  template<class T, class ...Args>
  inline void read(T &x, Args&... args) {read(x); read(args...);}
  template<class T>
  inline void write(T x) {
    static char stk[128];
    int top = 0;
    if(x == 0) {putc('0'); return;}
    if(x < 0) putc('-'), x = -x;
    while(x) stk[top++] = x % 10, x /= 10;
    while(top) putc(stk[--top] + '0');
  }
  template<class T, class ...Args>
  inline void write(T x, Args... args) {write(x); putc(' '); write(args...);}
  inline void space() {putc(' ');}
  inline void endl() {putc('\n');}
  struct _flush {~_flush() {flush();}} __flush;
};
using io::read; using io::write; using io::flush; using io::space; using io::endl; using io::getc; using io::putc;
namespace vb{
  int bg[300005],l[1001],r[1001],s;
  bool a[300005],in[300005];
  int st[1001][351],tp[1001];
  inline void build(){
    for(int i=1;i<=c+1;i++) bg[i]=(i-1)/w2+1;
    s=bg[c+1];
    for(int i=1;i<=s;i++) l[i]=r[i-1]+1,r[i]=r[i-1]+w2;
    r[s]=c+1;
  }
  inline void modify(int i){
    if(!i) return;
    a[i]^=1;
    if(a[i]&&!in[i]){
      int x=bg[i];
      st[x][++tp[x]]=i,in[i]=1;
    }
  }
  inline int query(int x,int y){
    if(bg[x]==bg[y]){
      for(int i=x;i<=y;i++) if(a[i]) return assert(val[i]!=0),val[i];
      return -1;
    }
    x--,y++;
    for(int i=x+1;i<=r[bg[x]];i++) if(a[i]) return assert(val[i]!=0),val[i];
    for(int i=y-1;i>=l[bg[y]];i--) if(a[i]) return assert(val[i]!=0),val[i];
    for(int i=bg[x]+1,j=bg[y];i<j;i++){
      while(tp[i]&&!a[st[i][tp[i]]]) in[st[i][tp[i]--]]=0;
      if(tp[i]) return assert(val[st[i][tp[i]]]!=0),val[st[i][tp[i]]];
    }
    return -1;
  }
}
namespace tr{
  int fa[300001],sz[300001],son[300001],top[300001],dep[300001];
  inline void dfs1(int i){
    sz[i]=1,dep[i]=dep[fa[i]]+1;
    for(int j:to[i]){
      if(j==fa[i]) continue;
      fa[j]=i,dfs1(j);
      sz[i]+=sz[j];
      if(sz[j]>sz[son[i]]) son[i]=j;
    }
  }
  inline void dfs2(int i,int tp){
    top[i]=tp;
    if(son[i]) dfs2(son[i],tp);
    for(int j:to[i]) if(j!=fa[i]&&j!=son[i]) dfs2(j,j);
  }
  inline int lca(int x,int y){
    while(top[x]!=top[y]){
      if(dep[top[x]]<dep[top[y]]) swap(x,y);
      x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
  }
}
struct p{
  int l,r,b,id,x,y,lca;
  bool operator <(const p &j) const {
    if (b == j.b) {
      if (l == j.l) return false;
      return (l < j.l) ^ (b & 1);
    }
    return b < j.b;
  }
}q[300001];
inline void dfs(int i,int fa){
  v[l[i]=++cnt]=a[i];
  for(int j:to[i]) if(j!=fa) dfs(j,i);
  v[r[i]=++cnt]=a[i];
}
int main(){
  read(n,m);
  for(int i=1;i<=n;i++) read(a[i]),val[i]=a[i];
  sort(val+1,val+n+1),c=unique(val+1,val+n+1)-val-1;
  for(int i=1;i<=n;i++) a[i]=lower_bound(val+1,val+c+1,a[i])-val;
  for(int i=1;i<n;i++){
    read(x,y);
    to[x].push_back(y),to[y].push_back(x);
  }
  dfs(1,0);
  tr::dfs1(1),tr::dfs2(1,1);
  for(int i=1;i<=m;i++){
    read(x),read(y),read(q[i].x),read(q[i].y),q[i].id=i;
    if(l[x]>l[y]) swap(x,y);
    if(r[x]<r[y]) q[i].l=r[x],q[i].r=l[y],q[i].lca=tr::lca(x,y);
    else q[i].l=l[x],q[i].r=l[y];
    q[i].b=q[i].r/w1;
    q[i].x=lower_bound(val+1,val+c+1,q[i].x)-val,q[i].y=upper_bound(val+1,val+c+1,q[i].y)-val-1;
  }
  sort(q+1,q+m+1);
  vb::build();
  for(int i=1;i<=m;i++){
    assert(ans[q[i].id]==0);
    if(q[i].x>q[i].y){
      ans[q[i].id]=-1;
      continue;
    }
    while(rt<q[i].r) vb::modify(v[++rt]);
    while(lt>q[i].l) vb::modify(v[--lt]);
    while(rt>q[i].r) vb::modify(v[rt--]);
    while(lt<q[i].l) vb::modify(v[lt++]);
    if(q[i].lca) vb::modify(a[q[i].lca]);
    ans[q[i].id]=vb::query(q[i].x,q[i].y);
    if(q[i].lca) vb::modify(a[q[i].lca]);
    assert(ans[q[i].id]!=0);
  }
  for(int i=1;i<=m;i++) write(ans[i]),endl();
}