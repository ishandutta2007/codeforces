#include<bits/stdc++.h>
using namespace std;
/*void chk(int x,int y){
	while(
}*/
#define LL long long
int main(){
//	scanf("%lld",&x);
//	for(LL i=1;i*i<=x;++i){
//		if(x%i==0){chk(i,x/i);}
//	}
//	printf("%lld %lld",ans1,ans2);
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		LL MIN=1e18,S=0,ans=0,a=0;
		for(int i=1;i<=n;++i){
			scanf("%lld",&a);
			S+=a;
			if(S<MIN)MIN=S;
			ans=max(ans,S-MIN);
			if(i!=n)ans=max(ans,S);
		}
	//	cerr<<"? "<<ans<<endl;
		if(ans>=S)puts("NO");
			else puts("YES");
	}
	return 0;
}