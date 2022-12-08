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
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
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
	while(c<'0'||c>'9'){rev|=c=='-';c=Getchar();if(Terminal)return 0;}
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

const int inf=0x3f3f3f3f;
const int N=254,M=100005;
int mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,m,tot,a[N][N],num[N][N],fa[N*N],vis[N*N];
char s[N][N];

inline int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
inline void merge(int x,int y){
	fa[find(x)]=find(y);
}
inline void add(int x,int y){
	ch(a[x][x],1);ch(a[y][y],1);
	ch(a[x][y],mod-1);ch(a[y][x],mod-1);
}
inline int det(){
	int rev=0,ans=1;
	for(int i=1;i<tot;i++){
		int t=0;
		for(int j=i;j<tot;j++)
			if(a[j][i]){t=j;break;}
		if(!t) return 0;
		if(i!=t){
			for(int j=i;j<tot;j++)
				swap(a[i][j],a[t][j]);
			rev^=1;
		}
		ans=(ll)ans*a[i][i]%mod;
		int INV=exp(a[i][i],mod-2);
		for(int j=i+1;j<tot;j++){
			if(!a[j][i]) continue;
			int p=(ll)a[j][i]*INV%mod;
			for(int k=i;k<tot;k++)
				ch(a[j][k],-(ll)a[i][k]*p);
		}
	}
	if(rev) ans=-ans;
	if(ans<0) return ans+mod;
	return ans;
}
inline int solve(int use){
	tot=0;clr(vis,0);
	clr(a,0);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++){
			int c=(i&1)^(j&1);
			if(c!=use) continue;
			if(!vis[find(num[i][j])])
				vis[find(num[i][j])]=++tot;
			num[i][j]=vis[find(num[i][j])];
			if(tot>210) return 0;
		}
//	debug(tot);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='*'){
				if(((i&1)^(j&1))==use) add(num[i-1][j-1],num[i][j]); else add(num[i][j-1],num[i-1][j]);
			}
	return det();
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=0,cnt=0;i<=n;i++)	
		for(int j=0;j<=m;j++)
			num[i][j]=++cnt,fa[cnt]=cnt;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='/') merge(num[i-1][j],num[i][j-1]); else if(s[i][j]=='\\') merge(num[i-1][j-1],num[i][j]);
	printf("%d\n",(solve(0)+solve(1))%mod);
	return 0;
}