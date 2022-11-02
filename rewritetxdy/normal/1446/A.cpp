//# pragma GCC optimize ("O2")
//# pragma comment(linker, "/STACK:1024000000,1024000000")
#include<bits/stdc++.h>
#define lb(x) ((x)&(-x))
#define out(i,a,now) for(LL i=a.be[now],to=a.v[i];~i;i=a.ne[i],to=a.v[i])
#define fo(i,a,b) for(LL i=(a);i<=(b);++i)
#define fd(i,a,b) for(LL i=(a);i>=(b);--i)
#define mid ((l+r)>>1)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define mp(a,b) make_pair(a,b)
#define qk(x) memset(x,0,sizeof(x))
#define RG register
#define SF scanf
#define PF printf
#define FP freopen
#define FI first
#define SE second
#define cpy(a,b) memcpy(a,b,sizeof(a))//b to a
#define pi 3.1415926535897932384626433832
#ifdef Mogician
#endif
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair<LL,LL> Pair;
template <class T> void cmax(T &a,T b){
    a=max(a,b);
}
template <class T> void cmin(T &a,T b){
    a=min(a,b);
}
const LL maxn=201000;
LL a[maxn],n,ans[maxn],top,w;
int main(){
	LL T;
	SF("%lld",&T);
	while (T--){
		SF("%lld%lld",&n,&w);
		LL x,flag=0; top=0;
		fo(i,1,n){
			SF("%lld",&x);
			if (x>=(w+1)/2 && x<=w){
				flag=1; ans[++top]=i;
			}
			a[i]=x;
		}
		if (flag){
			puts("1");
			printf("%lld\n",ans[1]);
		}
		else{
			LL tot=0;
			fd(i,n,1){
				if (a[i]>=(w+1)/2) continue;
				tot+=a[i];
				ans[++top]=i;
				if (tot>=(w+1)/2) break; 
			} 
			if (tot>=(w+1)/2){
				printf("%lld\n",top);
				fo(j,1,top) printf("%lld ",ans[j]);
			}
			else puts("-1");
		}
	}
}