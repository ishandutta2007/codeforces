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

const int N=35,M=100005,mod=1e9+7;
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

struct matrix{int a[N][N];}ans,f[N<<1][N],l[N],r[N];
int k;
ll n;
inline matrix operator * (const matrix &a,const matrix &b){
	matrix tmp;
	for(int i=0;i<=k;i++)
		for(int j=0;j<=k;j++){
			ll temp=0;
			for(int t=0;t<=k;t++)
				temp+=(ll)a.a[i][t]*b.a[t][j]%mod;
			tmp.a[i][j]=temp%mod;
		}
	return tmp;
}
void print(const matrix &a){
	for(int i=0;i<=k;i++,puts(""))
		for(int j=0;j<=k;j++)
			printf("%d ",a.a[i][j]);
	puts("");
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%lld%d",&n,&k);
	int m=1;ll tmp=1;
	while(tmp<n) tmp*=k,m++;
//	debug(m);
	for(int i=0;i<k;i++){
		matrix &a=f[0][i];
		for(int j=0;j<=k;j++)
			a.a[i][j]=a.a[j][j]=1;
//		print(f[0][i]);
	}
	for(int j=1;j<m;j++){
		l[0]=f[j-1][0];
		for(int i=1;i<k;i++)
			l[i]=f[j-1][i]*l[i-1];
		r[k-1]=f[j-1][k-1];
		for(int i=k-2;~i;i--)
			r[i]=r[i+1]*f[j-1][i];
		for(int i=0;i<k;i++){
			f[j][i]=r[i];
			if(i) f[j][i]=l[i-1]*f[j][i];
		}
	}
	int s=0;
	for(int i=0;i<=k;i++)
		ans.a[i][i]=1;
	while(n){
		ll t=1,lg=0;
		for(int i=1;i<m;i++,t*=k)
			if(t<=n/k) lg=i; else break;
		ans=f[lg][s]*ans;
//		debug(lg);debug(s);
		s=(s+1)%k;n-=t;
	}
//	print(ans);
	int res=0;
	for(int i=0;i<=k;i++)
		ch(res,ans.a[i][k]);
	printf("%d\n",res);
	return 0;
}