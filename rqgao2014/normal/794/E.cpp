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

const int N=300005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,a[N],ans[N];

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),gmax(ans[n-1],a[i]);
	for(int i=1;i<n;i++){
		int t=n-min(i-1,n-i-1)*2-3;
		if(t<0) t+=2;
		gmax(ans[t],min(a[i],a[i+1]));
	}
	for(int i=1;i<n;i++)
		gmax(ans[n-min(i-1,n-i-1)*2-2],max(a[i],a[i+1]));
	for(int i=2;i<n;i++)
		gmax(ans[i],ans[i-2]);
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}