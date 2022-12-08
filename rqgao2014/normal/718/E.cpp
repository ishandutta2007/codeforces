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

const int N=100055,M=100005,mod=1e9+7;
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

struct node{int to,next,w;}p[N<<2];
int n,tot,ans,head[N],si[8][256];
int d[N],dis[8][N],a[8][8],L[8][256],R[8][256];
char s[N];
bool vis[N];
queue<int> q;
vector<pii> g[8][256];
pii st[N];

inline void add(int x,int y,int z){
	p[++tot]=(node){y,head[x],z};head[x]=tot;
	p[++tot]=(node){x,head[y],z};head[y]=tot;
}
void spfa(int S){
	for(int i=1;i<=n+10;i++)
		d[i]=inf;
	q.push(S);d[S]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=p[i].next){
			int y=p[i].to;
			if(d[y]>d[x]+p[i].w){
				d[y]=d[x]+p[i].w;
				if(!vis[y]) q.push(y),vis[y]=1;
			}
		}
	}
}
void ins(int x){
	si[st[x].FF][st[x].SS]++;
}
bool getans(){
	ans=0;
	for(int l=0;l<8;l++)
		for(int ml=0;ml<256;ml++){
			if(!L[l][ml]) continue;
			for(int r=0;r<8;r++)
				for(int mr=0;mr<256;mr++){
					if(!R[r][mr]) continue;
					int res=R[r][mr]-L[l][ml];
					for(int i=0;i<8;i++){
						int x=a[l][i]+a[r][i];
						if(ml&(1<<i)) x++; else x--;
						if(mr&(1<<i)) x++; else x--;
						gmin(res,x>>1);
					}
					gmax(ans,res);
				}
		}
	for(int l=0;l<8;l++)
		for(int ml=0;ml<256;ml++){
			if(!L[l][ml]) continue;
			for(int r=0;r<8;r++)
				for(int mr=0;mr<256;mr++){
					if(!R[r][mr]) continue;
					int res=R[r][mr]-L[l][ml];
					if(res<ans) continue;
					for(int i=0;i<8;i++){
						int x=a[l][i]+a[r][i];
						if(ml&(1<<i)) x++; else x--;
						if(mr&(1<<i)) x++; else x--;
						gmin(res,x>>1);
					}
					if(res==ans) g[r][mr].pb(mp(l,ml));
				}
		}
}

int main(){
	read(n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		add(n+1+s[i]-'a',i,1);
	for(int i=1;i<n;i++)
		add(i,i+1,2);
	for(int i=0;i<8;i++){
		spfa(i+n+1);
		cpy(dis[i],d);
		for(int j=0;j<8;j++)
			a[i][j]=d[j+n+1];
	}
	for(int i=1;i<=n;i++){
		int c=s[i]-'a',mask=0;
		for(int j=0;j<8;j++)
			if(dis[j][i]==a[j][c]+1) mask|=1<<j;
		if(!L[c][mask]) L[c][mask]=i;
		R[c][mask]=i;
		st[i]=mp(c,mask);
	}
	getans();printf("%d ",ans);
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(i>ans) ins(i-ans);
		int x=st[i].FF,y=st[i].SS;
		for(int j=0;j<g[x][y].size();j++)
			cnt+=si[g[x][y][j].FF][g[x][y][j].SS];
	}
	printf("%lld\n",cnt);
	return 0;
}