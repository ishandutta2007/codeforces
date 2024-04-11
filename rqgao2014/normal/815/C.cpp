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

const int N=5005,M=100005,mod=1e9+7;
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

struct node{int to,next;}p[N];
int n,b,tot,head[N],c[N],d[N],si[N];
int dp[N][N][2],tmp[N][2];
bool vis[N];
inline void add(int x,int y){
	p[++tot]=(node){y,head[x]};head[x]=tot;
}
inline void dfs(int x){
	vis[x]=1;si[x]=0;
	clr(dp[x],0x3f);
	dp[x][0][0]=0;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		dfs(y);clr(tmp,0x3f);
		for(int l=0;l<=si[x];l++)
			for(int lx=0;lx<2;lx++){
				if(dp[x][l][lx]>b) continue;
				for(int r=0;r<=si[y];r++)
					for(int rx=0;rx<2;rx++)
						gmin(tmp[l+r][lx|rx],dp[x][l][lx]+dp[y][r][rx]);
			}
		si[x]+=si[y];
		cpy(dp[x],tmp);
	}
	si[x]++;
	cpy(tmp,dp[x]);
	for(int i=0;i<=si[x];i++){
		dp[x][i][0]=min(tmp[i][0],i?tmp[i-1][0]+c[x]:inf);
		if(i) dp[x][i][1]=min(inf,min(tmp[i-1][1],tmp[i-1][0])+d[x]);
	}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++){
		int fa=0;
		scanf("%d%d",&c[i],&d[i]);
		d[i]=c[i]-d[i];
		if(i>1) scanf("%d",&fa);
		add(fa,i);
	}
	dfs(1);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(dp[1][i][0]<=b||dp[1][i][1]<=b) ans=i;
	printf("%d\n",ans);
	return 0;
}