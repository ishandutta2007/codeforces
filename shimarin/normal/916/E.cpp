#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
namespace IO {
static const int OUT_BUF = 1 << 23;
inline void myPutchar(char x) {
	static char pbuf[OUT_BUF], *pp = pbuf;
	struct _flusher {
		~_flusher() {
			fwrite(pbuf, 1, pp - pbuf, stdout);
		}
	};
	static _flusher outputFlusher;
	if (pp == pbuf + OUT_BUF) {
		fwrite(pbuf, 1, OUT_BUF, stdout);
		pp = pbuf;
	}
	*pp++ = x;
}

#define putchar myPutchar
template<typename T>
inline void print_(T x) {
	if (x == 0) {
		putchar('0');
		return;
	}
	static int num[40];
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	for (*num = 0; x; x /= 10) {
		num[++*num] = x % 10;
	}
	while (*num){
		putchar(num[*num] ^ '0');
		--*num;
	}
}

template<typename T>
inline void print(T x, char ch = '\n') {
	print_(x);
	putchar(ch);
}
}

const int N = 3e5+10;      
int n,m,rt,a[N];
  
int tim,fa[N][20],st[N],ed[N],dep[N],idfn[N];
poly e[N];
inline void dfs(int x,int ff){ 
    dep[x]=dep[fa[x][0]]+1;
    st[x]=++tim,idfn[tim]=x;
	For(i,1,18) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (auto v:e[x]) if (v!=fa[x][0]) fa[v][0]=x,dfs(v,x);
    ed[x]=tim;  
}
 
ll sum[N<<2],lazy[N<<2],len[N<<2]; 
inline void mark(int u,ll v){
    sum[u]+=v*len[u],lazy[u]+=v;
}  
inline void pushdown(int u){
    if (lazy[u]) mark(u<<1,lazy[u]),mark(u<<1^1,lazy[u]),lazy[u]=0; 
}
inline void build(int l,int r,int u){ 
    len[u]=r-l+1;  
    if (l==r) return sum[u]=a[idfn[l]],void(0);
    int mid=l+r>>1;  
    build(l,mid,u<<1),build(mid+1,r,u<<1^1);
    sum[u]=sum[u<<1]+sum[u<<1^1];
}    
inline void update(int l,int r,int u,int ql,int qr,ll v){
	if (l>=ql&&r<=qr) return mark(u,v),void(0);
    int mid=l+r>>1;pushdown(u);
    if (ql<=mid) update(l,mid,u<<1,ql,qr,v); 
    if (qr>mid) update(mid+1,r,u<<1^1,ql,qr,v); 
    sum[u]=sum[u<<1]+sum[u<<1^1];
}  
inline ll query(int l,int r,int u,int ql,int qr){ 
    if (l>=ql&&r<=qr) return sum[u];  
    int mid=l+r>>1;pushdown(u);
    ll ret=0;
    if (ql<=mid) ret+=query(l,mid,u<<1,ql,qr);
    if (qr>mid) ret+=query(mid+1,r,u<<1^1,ql,qr); 
    return ret;
}

inline int Jump(int x,int k){
	Dow(i,18,0) if (k&(1<<i)) x=fa[x][i];
    return x;     
}   
inline int LCA(int x,int y){  
    if (dep[x]>dep[y]) swap(x,y);    
    if (dep[x]!=dep[y]) Dow(i,18,0) if (dep[fa[y][i]]>=dep[x]) y=fa[y][i];   
    if (x==y) return x;  
    Dow(i,18,0) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];    
}  
inline int Lca(int x,int y){    
    int a1=LCA(x,y),a2=LCA(x,rt),a3=LCA(y,rt);   
    if (dep[a1]<dep[a2]) a1=a2;   
    if (dep[a1]<dep[a3]) a1=a3; 
    return a1;   
}

inline void Modify(int x,ll v){    
    if (x==rt) update(1,n,1,1,n,v);
    else if (st[rt]>=st[x]&&st[rt]<=ed[x]){
        update(1,n,1,1,n,v);
        int z=Jump(rt,dep[rt]-dep[x]-1);     
        update(1,n,1,st[z],ed[z],-v);
    } else update(1,n,1,st[x],ed[x],v);
}
inline ll Query(int x){   
    if (x==rt) return sum[1];
    else if (st[rt]>=st[x]&&st[rt]<=ed[x]){   
        int z=Jump(rt,dep[rt]-dep[x]-1);      
        return sum[1]-query(1,n,1,st[z],ed[z]);  
    } else return query(1,n,1,st[x],ed[x]);  
}

int main(){
    n=read(),m=read();
	For(i,1,n) a[i]=read();
	FOR(i,1,n){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
    rt=1,dfs(1,0),build(1,n,1);
	while (m--){
    	int op=read();   
        if (op==1) rt=read();
        if (op==2){
        	int x=read(),y=read(),z=read(),lca=Lca(x,y);
            Modify(lca,z);  
        }
        if (op==3) IO::print(Query(read())); 
    }
}