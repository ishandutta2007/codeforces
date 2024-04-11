#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],n,t_case;
ll ans[maxn],m,pre[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%lld",&n,&m);
		clear(ans,n);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			pre[i]=pre[i-1]+a[i]+m;
			for(ri j=0;j<i;++j)ckmax(ans[i-j],pre[i]-pre[j]);
		}
		for(ri i=1;i<=n;++i)ckmax(ans[i],ans[i-1]);
		for(ri i=n-1;~i;--i)ckmax(ans[i],ans[i+1]-m);
		for(ri i=0;i<=n;++i)printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}