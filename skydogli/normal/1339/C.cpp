#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MN 200005
int T,n;
int a[100005];
int LOG(int a){
	int ti=1,v=2;
	while(v-1<a){
		v<<=1;ti++;
	}
	return ti;
}
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		int mx=-2e9,ans=0;
		for(int i=1;i<=n;++i){
			if(mx>a[i])ans=max(ans,LOG(mx-a[i]));
			mx=max(mx,a[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}