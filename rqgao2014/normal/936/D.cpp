#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define all(a) a.begin(),a.end()
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
template<class T> inline void gmin(T &x,const T &y){x=x>y?y:x;}
template<class T> inline void gmax(T &x,const T &y){x=x<y?y:x;}
template<class T> inline bool Gmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T> inline bool Gmax(T &x,const T &y){return x<y?x=y,1:0;}
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
const int N=2000005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int i,j,k;}from[N][2][2];
int n,m,m1,m2,d,xx[N],o1[N>>1],o2[N>>1];
int dp[N][2][2],last[N][2];
bool a[N][2];
vi mov;
vector<pii> shot;

inline int Get(int x){return lower_bound(xx+1,xx+n+1,x)-xx;}
inline void get(int i,int j,int k){
//	dprintf("%d %d %d\n",i,j,k);
	if(!i){
		if(j) mov.pb(0);
		return;
	}
	int ti=from[i][j][k].i,tj=from[i][j][k].j,tk=from[i][j][k].k;
	if(ti==i){
		mov.pb(xx[i-1]+1);
		get(ti,tj,tk);
		return;
	}
	if(!a[i][j]){get(ti,tj,tk);return;}
	if(tk){shot.pb(mp(dp[i][j][k],j));get(Get(last[i][j]),j,1);return;}
	shot.pb(mp(dp[i][j][k],j));get(Get(dp[i][j][k]),j,0);
}


int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	scanf("%d%d%d%d",&n,&m1,&m2,&d);
	m=m1+m2;
	if(!m){puts("Yes\n0\n\n0");return 0;}
	for(int i=1;i<=m1;i++)
		scanf("%d",&o1[i]),xx[i]=o1[i],xx[i+m]=o1[i]-1;
	for(int i=1;i<=m2;i++)
		scanf("%d",&o2[i]),xx[i+m1]=o2[i],xx[i+m+m1]=o2[i]-1;
	sort(xx+1,xx+m*2+1);
	n=unique(xx+1,xx+m*2+1)-xx-1;
	if(!xx[1]){
		for(int i=1;i<n;i++)
			xx[i]=xx[i+1];
		n--;
	}
	for(int i=1;i<=m1;i++)
		a[Get(o1[i])][0]=1;
	for(int i=1;i<=m2;i++)
		a[Get(o2[i])][1]=1;
/*	for(int i=1;i<=m1;i++)
		a[o1[i]][0]=1;
	for(int i=1;i<=m2;i++)
		a[o2[i]][1]=1;*/
	for(int j=0;j<2;j++){
		int L=0;
		for(int i=1;i<=n;i++)
			last[i][j]=L,L=a[i][j]?xx[i]:L;
	}
	clr(dp,0x3f);
	dp[0][0][1]=dp[0][1][1]=0;
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<2;j++)
			for(int k=1;~k;k--)
				if(!a[i][j^1]&&Gmin(dp[i][j^1][0],dp[i][j][k])) from[i][j^1][0]=(node){i,j,k};
		for(int j=0;j<2;j++)
			for(int k=1;~k;k--){
				int tmp=dp[i][j][k];
				if(tmp>xx[i])continue;
				if(!a[i+1][j]){
					if(Gmin(dp[i+1][j][k],tmp)) from[i+1][j][k]=(node){i,j,k};
					continue;
				}
				if(tmp+d>xx[i]) continue;
				if(k){
					if(Gmin(dp[i+1][j][1],tmp+d)) from[i+1][j][1]=(node){i,j,k};
				}
				else if(last[i+1][j]+1<=xx[i]){
					if(Gmin(dp[i+1][j][1],max(tmp+d,last[i+1][j]+1))) from[i+1][j][1]=(node){i,j,k};
				}
			}
	}
	for(int k=1;~k;k--)
		for(int j=0;j<2;j++)
			if(dp[n][j][k]<xx[n]){
				puts("Yes");
				get(n,j,k);
				reverse(all(mov));
				reverse(all(shot));
				for(int i=0;i<SZ(mov)-1;i++)
					assert(mov[i]<mov[i+1]);
				printf("%d\n",SZ(mov));
				for(int i:mov) printf("%d ",i);puts("");
				printf("%d\n",SZ(shot));
				for(auto i:shot) printf("%d %d\n",i.FF,i.SS+1);
				return 0;
			}
	puts("No");
				
	return 0;
}