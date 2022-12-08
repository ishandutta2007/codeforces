#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define HEAP(...) priority_queue<__VA_ARGS__ >
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > > 
#define pii pair<int,int> 
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x<<"="<<x<<endl
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define dputs(...) fputs(__VA_ARGS__,stderr)
#define debuge dprintf("isok")
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define SZ(x) ((int)x.size())
using namespace std;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
const int BufferSize=1<<16;
char buffer[BufferSize],*Bufferhead,*Buffertail;
bool Terminal;
inline char Getchar(){
	if(Bufferhead==Buffertail){
		int l=fread(buffer,1,BufferSize,stdin);
		if(!l){Terminal=1;return 0;}
		Buffertail=(Bufferhead=buffer)+l;
	}
	return *Bufferhead++;
}
template<class T>inline bool read(T &x){
	x=0;char c=Getchar(),rev=0;
	while(c<'0'||c>'9'){c=Getchar();rev|=c=='-';if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	if(c=='.'){
		c=Getchar();double t=0.1;
		while(c>='0'&&c<='9') x=x+(c-'0')*t,c=Getchar(),t=t/10;
	}
	x=rev?-x:x;
	return 1;
}
template<class T1,class T2> inline bool read(T1 &x,T2 &y){return read(x)&read(y);}
template<class T1,class T2,class T3> inline bool read(T1 &x,T2 &y,T3 &z){return read(x)&read(y)&read(z);}
template<class T1,class T2,class T3,class T4> inline bool read(T1 &x,T2 &y,T3 &z,T4 &w){return read(x)&read(y)&read(z)&read(w);}
inline bool reads(char *x){
	char c=Getchar();
	while(c<33||c>126){c=Getchar();if(Terminal)return 0;}
	while(c>=33&&c<=126) (*x++)=c,c=Getchar();
	*x=0;return 1;
}
template<class T>inline void print(T x,const char c='\n'){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[20];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
//--------------------------------head---------------------------------------------

const short inf=0x3f3f;
const int N=55,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

const int u[4][2]={1,0,0,1,-1,0,0,-1};
int n,m,k,sx,sy,tx,ty,cnt;
short dist=inf,st[N][N],st2[N][N];
char s[N][N],ans[N*N],now[N*N];
bool vis[N][N],use[256];

bool srch(int d){
	pii q[N*N];
	int h=1,t=1;
	q[t]=mp(sx,sy);
	for(int i=1;i<d;i++){
		int mn=128;
		for(int tt=t;h<=tt;h++){
			int x=q[h].FF,y=q[h].SS;
			for(int k=0;k<4;k++){
				int px=x+u[k][0],py=y+u[k][1];
				if(px<1||py<1||px>n||py>m||st[px][py]!=st[x][y]+1||st[px][py]+st2[px][py]!=d+1) continue;
				if(vis[px][py]) continue;
				if(s[px][py]==mn) q[++t]=mp(px,py); else if(s[px][py]<mn) mn=s[px][py],t=tt+1,q[t]=mp(px,py);
				vis[px][py]=1;
			}
		}
		
		now[i]=mn;
	}
}
void solve(){
	static pii q[5005];
	int h=1,t=1;
	q[t]=mp(sx,sy);st[sx][sy]=1;
	while(h<=t){
		int x=q[h].FF,y=q[h].SS;h++;
		for(int i=0;i<4;i++){
			int px=x+u[i][0],py=y+u[i][1];
			if(px<1||py<1||px>n||py>m||!use[s[px][py]]||st[px][py]) continue;
			st[px][py]=st[x][y]+1;
			q[++t]=mp(px,py);
		}
	}
	if(!st[tx][ty]){
		for(int i=1;i<=t;i++)
			st[q[i].FF][q[i].SS]=0;
		return;
	}
	q[++t]=mp(tx,ty);st2[tx][ty]=1;
	while(h<=t){
		int x=q[h].FF,y=q[h].SS;h++;
		for(int i=0;i<4;i++){
			int px=x+u[i][0],py=y+u[i][1];
			if(px<1||py<1||px>n||py>m||!use[s[px][py]]||st2[px][py]) continue;
			st2[px][py]=st2[x][y]+1;
			q[++t]=mp(px,py);
		}
	}
	if(st[tx][ty]&&st[tx][ty]<dist){
		dist=st[tx][ty];
		srch(dist);
		for(int i=1;i<=dist-2;i++)
			ans[i]=now[i];
	}
	else if(st[tx][ty]&&st[tx][ty]==dist){
		srch(dist);
		bool isok=0;
		for(int i=1;i<=dist-2;i++)
			if(now[i]<ans[i]){isok=1;break;} else if(now[i]>ans[i]) break;
		if(isok){
			for(int i=1;i<=dist-2;i++)
				ans[i]=now[i];
		}
	}
	cnt+=t;
	for(int i=1;i<=t;i++)
		vis[q[i].FF][q[i].SS]=st[q[i].FF][q[i].SS]=st2[q[i].FF][q[i].SS]=0;
}
void dfs(int x,char st='a'){
	if(x==k+1){
		solve();
		return;
	}
	for(char i=st;i<='z';i++)
		use[i]=1,dfs(x+1,i+1),use[i]=0;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	read(n,m,k);
	for(int i=1;i<=n;i++){
		reads(s[i]+1);
		for(int j=1;j<=m;j++)
			if(s[i][j]=='S') sx=i,sy=j; else if(s[i][j]=='T') tx=i,ty=j;
	}
	use['S']=use['T']=1;

	dfs(1);
	debug(cnt);
	dprintf("%d\n",(int)dist);
	if(dist>=inf) puts("-1"); else ans[dist-1]=0,printf("%s\n",ans+1);
	return 0;
}