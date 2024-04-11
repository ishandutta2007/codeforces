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

const int N=100005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

struct node{int to,next,w;}p[N<<1];
int n,tot,pos[N],du[N],head[N],f[N],ans;
bool vis[N];

void add(int x,int y,int z){
	p[++tot]=(node){y,head[x],z};head[x]=tot;
	p[++tot]=(node){x,head[y],z};head[y]=tot;
	du[x]++;du[y]++;
}
inline int inv(int x){
	int y=mod-2,ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}
void dfs(int x,int fa){
	int k=0,isok=0;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(y==fa) continue;
		dfs(y,x);isok=1;
		ch(k,mod+1-f[y]);
	}
	k=(ll)k*pos[x]%mod;
//	if(isok) debug(k);
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(y==fa) continue;
		ch(f[x],(ll)pos[x]*f[y]%mod*inv(mod+1-k)%mod);
	}
	if(!isok) f[x]=1;
//	printf("%d %d\n",x,f[x]);
}
void dfs2(int x,int fa,int f2,int now,int v){
//	if(x!=1) printf("%d %d %d\n",x,now,v);
	int p1=(mod+1-f[x])%mod,p2=(mod+1-f2)%mod;
	ch(ans,(ll)v*now%mod*(p1+1)%mod*inv(mod+1-(ll)p1*p2%mod)%mod);
	int k=(mod+1-f2)%mod,sum=f2;
	if(x==1) k=0;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(y==fa) continue;
		ch(k,mod+1-f[y]);ch(sum,f[y]);
	}
//	printf("%d %d %d\n",x,sum,k);
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(y==fa) continue;
		int p1=((ll)(k+f[y]-1)*pos[x]%mod+mod)%mod;
		
		int t1=(ll)pos[x]*(sum+mod-f[y])%mod*inv(mod+1-p1)%mod,t2;
//		printf("x=%d y=%d p1=%d p2=%d\n",x,y,p1,t1);
		dfs2(y,x,t1,(ll)now*(mod+1-t1)%mod,p[i].w);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
//	printf("%d\n",(int)(4ll*inv(10)%mod));
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		x++;y++;
		add(x,y,z);
	}
	for(int i=1;i<=n;i++) pos[i]=inv(du[i]);
//	for(int 
	dfs(1,0);
	dfs2(1,0,0,1,0);
	printf("%d\n",ans);
	return 0;
}