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

const int N=600005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int l[N],r[N],fa[N],si[N],dp[N],flag[N];
int s[N],top,tot,root,n;

inline void add(int x,int y){
	if(!x) return ;
	dp[x]+=y;flag[x]+=y;
}
inline void push(int x){
	if(!flag[x]) return;
	add(l[x],flag[x]);add(r[x],flag[x]);
	flag[x]=0;
}
inline void upt(int x){si[x]=si[l[x]]+si[r[x]]+1;}
void rotate(int x,int &k){
	int y=fa[x],z=fa[y];
	if(y==k) k=x; else if(l[z]==y) l[z]=x; else r[z]=x;
	fa[x]=z;fa[y]=x;
	if(l[y]==x) fa[r[x]]=y,l[y]=r[x],r[x]=y;
	else fa[l[x]]=y,r[y]=l[x],l[x]=y;
	upt(y);upt(x);
}
void splay(int x,int &k){
	int t=x;s[top=1]=t;
	while(t!=k) t=fa[t],s[++top]=t;
	while(top) push(s[top--]);
	while(x!=k){
		int y=fa[x],z=fa[y];
		if(y!=k){
			if(l[y]==x^l[z]==y) rotate(x,k); else rotate(y,k);
		}
		rotate(x,k);
	}
}
int rk(int x,int y){
	if(!x) return 0;
	push(x);
	if(dp[x]<y) return si[l[x]]+1+rk(r[x],y);
	return rk(l[x],y);
}
int get(int x,int y){
	if(y==si[l[x]]) return x;
	if(y>si[l[x]]) return get(r[x],y-si[l[x]]-1);
	return get(l[x],y);
}
void ins(int &x,int f,int y){
	if(!x){
		x=++tot;dp[x]=y;fa[x]=f;si[x]=1;
		return;
	}
	push(x);
	if(y<dp[x]) ins(l[x],x,y); else ins(r[x],x,y);
	upt(x);
}
void ins(int y){ins(root,0,y);splay(tot,root);}
void del(int x){
	x=get(root,x);splay(x,root);
	int t=l[x];
	while(r[t]) t=r[t];
	splay(t,l[x]);
	root=t;r[t]=r[x];fa[r[x]]=t;fa[t]=0;upt(t);
}
inline void add1(int x,int y){
	x--;y++;
	x=get(root,x);y=get(root,y);
	splay(x,root);splay(y,r[x]);
	add(l[y],1);
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d",&n);
	ins(0);
	for(int i=1;i<=n;i++) ins(inf);
//	debuge;
	for(int i=1;i<=n;i++){
		int x,y;read(x);read(y);
		int k1,k2;
		k1=rk(root,x);k2=rk(root,y);
		if(k1<k2) add1(k1,k2-1);
		del(k2);fa[0]=0;
		ins(x);
	}
	for(int i=n;~i;i--)
		if(dp[get(root,i)]<inf){printf("%d\n",i);break;}
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}