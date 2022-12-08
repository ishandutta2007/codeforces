#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=100005,M=N<<2,mod=1e9+7,inf=0x3f3f3f3f;
const pii zero=mp(-inf,-inf);
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar(),rev=0;
	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=rev?-x:x;
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int to,next,w;}p[N<<1];
int a[N],ansu,ansv,d;
int n,m,tot=1,L,R,res,root,head[N],u[N],v[N],w[N],seq[N];
pii now[N];
bool vis[N];
inline void add(int x,int y,int z){
	p[++tot]=(node){y,head[x],z};head[x]=tot;
	p[++tot]=(node){x,head[y],z};head[y]=tot;
}
namespace sgt{
	pii p[M];
	int c[M][2],root,cnt;
	inline void clear(){
		root=cnt=0;
		p[0]=mp(-inf,-inf);
	}
	inline void ch(int l,int r,int x,pii b,int &k=root){
		if(!k){k=++cnt;p[k]=zero;clr(c[k],0);}
		gmax(p[k],b);
		if(l==r) return;
		int mid=l+r>>1;
		if(x<=mid) ch(l,mid,x,b,c[k][0]); else ch(mid+1,r,x,b,c[k][1]);
	}
	inline pii get(int l,int r,int x,int y,int k=root){
		if(!k) return zero;
		if(x<=l&&r<=y) return p[k];
		int mid=l+r>>1;pii ans=zero;
		if(x<=mid) gmax(ans,get(l,mid,x,y,c[k][0]));
		if(y>mid) gmax(ans,get(mid+1,r,x,y,c[k][1]));
		return ans;
	}
}

inline int getsize(int x,int f){
	int tmp=1;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]||y==f) continue;
		tmp+=getsize(y,x);
	}
	return tmp;
}
inline int getroot(int x,int f){
	int now=1,tmp=0;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to,t;
		if(vis[y]||y==f) continue;
		t=getroot(y,x);now+=t;gmax(tmp,t);
	}
	gmax(tmp,m-now);
	if(tmp<res) res=tmp,root=x;
	return now;
}
inline void dfs(int x,int f,int len,int val){
	gmax(now[len],mp(val,x));
	gmax(d,len);
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]||y==f) continue;
		dfs(y,x,len+1,val+p[i].w);
	}
}
inline void dfs(int x){
	if(m<=L) return;
	vis[x]=1;seq[++tot]=x;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]) continue;
		res=m=getsize(y,x);getroot(y,x);
		dfs(root);
	}
}
inline void prepare(){
	res=m=n;getroot(1,0);
	tot=0;dfs(root);
}
inline bool solve(int x){
	vis[x]=1;sgt::clear();
	int tmp=0;
	sgt::ch(0,n,0,mp(0,x));
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y])continue;
		d=0;dfs(y,x,1,p[i].w);
		gmin(d,R);
		for(int j=1;j<=d;j++){
			pii tmp=sgt::get(0,n,max(0,L-j),R-j);
			if(now[j].FF+tmp.FF>=0){
				ansu=now[j].SS;ansv=tmp.SS;
				return 1;
			}
		}
		for(int j=1;j<=d;j++)
			sgt::ch(0,n,j,now[j]),now[j]=zero;
	}
	return 0;
}
inline bool check(int x){
	clr(vis,0);
	for(int i=1;i<=n;i++) now[i]=zero;
	for(int i=1;i<n;i++)
		p[i<<1].w=p[i<<1|1].w=(w[i]>=x)?1:-1;
	for(int i=1;i<=n&&seq[i];i++)
		if(solve(seq[i])) return 1;
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
#endif
	read(n);read(L);read(R);
	for(int i=1;i<n;i++)
		read(u[i]),read(v[i]),read(w[i]),add(u[i],v[i],0),a[i]=w[i];
	sort(a+1,a+n);
	int k=unique(a+1,a+n)-a-1;
	prepare();
	int l=1,r=k;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(a[mid])) l=mid; else r=mid-1;
	}
	check(a[r]);
	printf("%d %d\n",ansu,ansv);
	return 0;
}