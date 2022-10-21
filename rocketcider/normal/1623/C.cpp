#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],m,n,t_case;
inline bool check(int k){
	memcpy(b,a,n+1<<2);
	for(ri i=n;i>=3;--i){
		ri d=min(max((b[i]-k)/3,0),a[i]/3);
		b[i-2]+=2*d,b[i-1]+=d,b[i]-=3*d;
	}
	for(ri i=1;i<=n;++i)
		if(b[i]<k)
			return false;
	return true;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ri ans=0,l=1,r=1e9;
		while(l<=r){
			ri mid=l+r>>1;
			if(check(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}