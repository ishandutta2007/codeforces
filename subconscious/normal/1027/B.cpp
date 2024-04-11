#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int n,q,x,y;
int main(){
	scanf("%d%d",&n,&q);
	rep(i,q){
		scanf("%d%d",&x,&y);
		ll ans=0;
		if((x+y)%2==0){
			ans+=1ll*(x-1)/2*n;
			if((x-1)%2==1)ans+=(n+1)/2;
			ans+=(y+1)/2;
		}else{
			ans+=(1ll*n*n+1)/2;
			ans+=1ll*(x-1)/2*n;
			if((x-1)%2==1)ans+=n/2;
			ans+=(y+1)/2;
		}
		printf("%lld\n",ans);
	}
}