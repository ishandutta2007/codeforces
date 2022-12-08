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
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=400005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar(),rev=0;
	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=rev?-x:x;
}
inline void print(int x){
	int m=0,a[10];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');puts("");
}	
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int u,v,w,num;}p[N];
int n,m,l[N],r[N],fa[N],mx[N],val[N],sta[N],w[N],num[N];
bool rev[N],id[N],s[N],key[N],in[N];
inline bool cmp(const node &a,const node &b){return a.w<b.w;}
inline bool cmp2(const node &a,const node &b){return a.num<b.num;}

inline void upt(int x){
	mx[x]=x;
	if(l[x]&&val[mx[l[x]]]>val[mx[x]]) mx[x]=mx[l[x]];
	if(r[x]&&val[mx[r[x]]]>val[mx[x]]) mx[x]=mx[r[x]];
	s[x]=key[x]^id[x]^s[l[x]]^s[r[x]];
}
inline bool isroot(int x){return l[fa[x]]!=x&&r[fa[x]]!=x;}
inline void push(int x){
	if(!rev[x]) return;
	swap(l[x],r[x]);rev[x]=0;
	rev[l[x]]^=1;rev[r[x]]^=1;
}
inline void rotate(int x){
	int y=fa[x],z=fa[y];
	if(!isroot(y)){if(l[z]==y) l[z]=x; else r[z]=x;}
	fa[x]=z;fa[y]=x;
	if(l[y]==x) fa[r[x]]=y,l[y]=r[x],r[x]=y;
	else fa[l[x]]=y,r[y]=l[x],l[x]=y;
	upt(y);upt(x);
}
inline void splay(int x){
	int t=x,top=1;sta[1]=x;
	while(!isroot(t)) sta[++top]=fa[t],t=fa[t];
	while(top) push(sta[top--]);
	while(!isroot(x)){
		int y=fa[x],z=fa[y];
		if(!isroot(y)){
			if(l[y]==x^l[z]==y) rotate(x); else rotate(y);
		}
		rotate(x);
	}
}
inline void access(int x){
	int t=x;
	for(int i=0;x;i=x,x=fa[x])
		splay(x),key[x]^=s[i]^s[r[x]],r[x]=i,upt(x);
	splay(t);
}
inline void makeroot(int x){
	access(x);rev[x]^=1;
}
inline void link(int x,int y){
	makeroot(x);access(y);
	fa[x]=y;key[y]^=s[x];upt(y);
}
inline void cut(int x,int y){
	makeroot(x);access(y);
	l[y]=fa[x]=0;upt(y);
}
inline int find(int x){
	access(x);
	while(l[x]) x=l[x];
	return x;
}
inline int calc(int x){
	access(x);return s[x];
}
inline int getmax(int x,int y){
	makeroot(x);access(y);
	return mx[y];
}
inline int check(int x){
	makeroot(x+n);
	access(p[x].u);
	return key[p[x].u];
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	if(n&1){
		for(int i=1;i<=m;i++)
			puts("-1");
		return 0;
	}
	for(int i=1;i<=m;i++){
		read(p[i].u),read(p[i].v);read(p[i].w);
		w[i]=p[i].w;p[i].num=i;
	}
	sort(w+1,w+m+1);
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=m;i++) num[i]=p[i].num;
	sort(p+1,p+m+1,cmp2);
//---------------read-------------------
	for(int i=1;i<=n+m;i++) mx[i]=i;
	for(int i=1;i<=n;i++) id[i]=1;
	int cnt=n;
	for(int i=1,ans=m;i<=m;i++){
		int x=p[i].u,y=p[i].v;
		val[i+n]=p[i].w;
		if(find(x)!=find(y)){
			if(calc(x)&&calc(y)) cnt-=2;
			link(i+n,x);link(i+n,y);
			in[i]=1;
		}
		else if(p[i].w<=w[ans]){
			int t=getmax(x,y)-n;
			if(val[t+n]>val[i+n]){
				cut(t+n,p[t].u);cut(t+n,p[t].v);
				link(i+n,x);link(i+n,y);
				in[t]=0;in[i]=1;
			}
		}
		if(cnt){puts("-1");continue;}
		while(!in[num[ans]]||check(num[ans])){
			int k=num[ans];
			if(in[k]) in[k]=0,cut(k+n,p[k].u),cut(k+n,p[k].v);
			ans--;
		}
		print(w[ans]);
	}
	return 0;
}