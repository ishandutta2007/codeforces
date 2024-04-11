#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		ll ans=0;
		for(ri i=1;i<=n;++i)scanf("%d",a+i),ans+=a[i],a[i]-=n-i;
		sort(a+1,a+n+1,greater<int>());
		for(ri i=1;i<=m;++i){
			if(a[i]+i-1<0)break;
			ans-=a[i]+i-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}