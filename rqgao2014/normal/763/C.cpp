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

const int N=200005,M=100005;
int mod;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
template<class T> inline void read(T &x){
	x=0;char ch=getchar(),rev=0;
	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=rev?-x:x;
}
template<class T> inline void print(T x){
	if(!x){puts("0");return;}
	if(x<0){putchar('-');x=-x;}
	int a[20],m=0;
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

int n,s,d,a[N],d1[N],d2[N];
bool vis[N],rev;
bool find(int x){
	x=(x%mod+mod)%mod;
	if((*lower_bound(a+1,a+n+1,x))==x) return 1;
	return 0;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
#endif
	ios::sync_with_stdio(0);
	read(mod);read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	if(n==mod){puts("0 1");return 0;}
	if(n*2>mod){
		for(int i=1;i<=n;i++) vis[a[i]]=1;
		n=0;rev=1;
		for(int i=0;i<mod;i++)
			if(!vis[i]) a[++n]=i;
	}else sort(a+1,a+n+1);
	a[n+1]=-1;
	if(n==1){
		printf("%d 1\n",a[1]+rev);
		return 0;
	}
	for(int i=1;i<=n;i++)
		d1[i]=(a[i]-a[1]+mod)%mod,d2[i]=(a[i]-a[2]+mod)%mod;
	sort(d1+1,d1+n+1);d1[n+1]=-1;
	int k=n,L=0,R=0;
	for(int i=1;i<=n;i++){
		int t=*lower_bound(d1+1,d1+n+1,d2[i]);
		if(t==d2[i]) k--;
	}
	if(!k){puts("-1");return 0;}
	d=(ll)(a[1]-a[2]+mod)*exp(k,mod-2)%mod;
	while(find(a[1]-(ll)(L+1)*d%mod)) L++;
	while(find(a[1]+(ll)(R+1)*d%mod)) R++;
	if(L+R+1<n){puts("-1");return 0;}
	s=(a[1]-(ll)L*d%mod+mod)%mod;
	if(rev) s=(s+(ll)n*d)%mod;
	printf("%d %d\n",s,d);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}