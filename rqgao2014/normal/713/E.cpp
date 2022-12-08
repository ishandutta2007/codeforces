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
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,m,a[N],f[N],g[N],h[N];

bool check(int x){
	for(int i=n;i;i--){
		//for h[i]
		h[i]=a[i]+x;
		if(i<n&&a[i]+x>=a[i+1]-1) gmax(h[i],h[i+1]);
		if(i<n&&a[i]+x<a[i+1]-1){
			gmax(h[i],g[i+1]);
			if(i<n-1&&a[i+2]-x<=a[i]+x+1) gmax(h[i],f[i+1]);
		}
		
		//for g[i]
		g[i]=a[i];
		if(i<n&&a[i+1]==a[i]+1) gmax(g[i],h[i+1]);
		if(i<n&&a[i+1]-x<=a[i]+1){
			gmax(g[i],g[i+1]);
			if(i<n-1&&a[i+2]-x<=a[i]+1) gmax(g[i],f[i+1]);
		}
		
		//for f[i]
		if(i==n) continue;
		f[i]=a[i]+x;
		gmax(f[i],g[i+1]);
		if(i<n-1&&a[i]+x>=a[i+2]-x-1){
			if(a[i]+x>=a[i+2]-1) gmax(f[i],h[i+2]);
			else{
				gmax(f[i],g[i+2]);
				if(i<n-2&&a[i+3]-x<=a[i]+x+1) gmax(f[i],f[i+2]);
			}
		}
	}
	if(h[1]>=m) return 1;
	if(g[1]+x>=m) return 1;
	int bnd=1;
	for(int i=1;i<n;i++){
		if(bnd>=a[i]-1) bnd=a[i]+x;
		if(bnd<a[i+1]-x-1) break;
		int k=1-min(1,a[i+1]-x);
		if(f[i]+k>=m) return 1;
	}
	return 0;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d%d",&m,&n);
//	debug(m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i;i--)
		a[i]=a[i]-a[1]+1;
	a[n+1]=2e9+1;
	int l=0,r=0;
	for(int i=1;i<n;i++) gmax(r,a[i+1]-a[i]-1);
	gmax(r,a[1]+m-a[n]-1);l=(r+1)/2;
	if(r!=a[1]+m-a[n]-1){
		int s,b[N];
		for(int i=2;i<=n;i++)
			if(r==a[i]-a[i-1]-1){s=i;break;}
		for(int i=1;i<=n;i++)
			b[i]=a[(s+i-2)%n+1];
		for(int i=n;i;i--) b[i]=(b[i]-b[1]+m)%m+1;
		cpy(a,b);
	}
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
//	printf("%d %d\n",l,r);
	while(l<r){
		int mid=l+r>>1;
//		debug(mid);
		if(check(mid)) r=mid; else l=mid+1;
	}
	printf("%d\n",r);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}