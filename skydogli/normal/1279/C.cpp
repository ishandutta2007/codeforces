#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,T,m,a[100005],b[100005],rk[100005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			rk[a[i]]=i;
		}
		int now=0;
		LL ans=0;
		for(int i=1;i<=m;++i){
			scanf("%d",&b[i]);
			now=max(now,i);
			if(rk[b[i]]<=now) ans++;
			else{ans+=((rk[b[i]]-i+1)*2)-1;now=rk[b[i]];}
		}
		printf("%lld\n",ans);
	}
	return 0;
}