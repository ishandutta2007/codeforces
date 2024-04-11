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

const int N=300005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,a[N],sum,ans,pw[N],ipw[N];

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	pw[0]=1;ipw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*2%mod,ipw[i]=(ll)ipw[i-1]*(mod+1)/2%mod;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum=((ll)sum*2+a[i-1])%mod;
		ch(ans,(ll)(pw[i-1]-1)*a[i]%mod);
		ch(ans,mod-sum);
	}
	printf("%d\n",ans);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}