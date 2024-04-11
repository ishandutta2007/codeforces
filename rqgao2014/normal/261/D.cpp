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
template<class T> inline void read(T &x){
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

vi nex[N];
int n,m,maxb,t,dp[2][4485],last[N],a[N],b[N];

int Main(int argv){
	for(int i=0;i<n;i++) read(a[i]),b[i]=a[i];
	sort(b,b+n);
	m=unique(b,b+n)-b;
	for(int i=0;i<n;i++) a[i]=lower_bound(b,b+m,a[i])-b;
//	for(int i=0;i<n;i++) printf("%d ",a[i]);puts("");
	for(int i=n-1;~i;i--)
		last[a[i]]=i+n;
	for(int i=n-1;~i;i--){
		nex[i].resize(m);
		for(int j=0;j<m;j++)
			nex[i][j]=last[j];
		last[a[i]]=i;
	}
	for(int i=n-1;~i;i--)	
		dp[0][a[i]]=i;
	int ans=1;
	for(int j=2,k=0;j<=m;j++){
		int mn=inf;
		k^=1;
		for(int i=j-2;i<m;i++){
			dp[k][i]=inf;
			if(mn<inf)
				dp[k][i]=mn/n*n+nex[mn%n][i];
			gmin(mn,dp[k^1][i]);
			if(dp[k][i]<(ll)n*t) ans=j;
		}
	}
	printf("%d\n",ans);
	return 0;
}
void clear(){

}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	int T;scanf("%d",&T);
	scanf("%d%d%d",&n,&maxb,&t);
	for(int i=1;i<=T;i++)
		clear(),Main(i);
	return 0;
}