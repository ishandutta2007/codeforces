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
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=100005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,a[N],b[N],c[N],d[N];
ll pw[N];

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%lld",&x);
		for(int j=0;j<=40;j++){
			if((1ll<<j)==x){a[j]++;break;}
			if((1ll<<j)>x){b[j-1]++;break;}
		}
	}
	bool ans=0;
	for(int i=1;i<=a[0];i++){
		c[0]=i;
		d[0]=a[0]-i+b[0];
		for(int j=1;j<40;j++){
			c[j]=min(c[j-1],a[j]);
			d[j-1]+=a[j]-c[j];
			d[j]=b[j];
		}
		bool isok=1;
		for(int j=39;~j;j--){
			d[j]+=d[j+1];
			if(d[j]>c[j]){isok=0;break;}
		}
		if(isok) {ans=1;printf("%d ",i);}
	}
	if(!ans) puts("-1"); else puts("");
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}