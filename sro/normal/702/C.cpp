#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[100005],b[100005];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",b+i);
	}
	b[0]=-0x3f3f3f3f3f3f3f3f;
	b[m+1]=0x3f3f3f3f3f3f3f3f;
	long long ans=0;
	for(int i=1;i<=n;i++){
		int pos=lower_bound(b+1,b+m+1,a[i])-b;
		ans=max(ans,min(b[pos]-a[i],a[i]-b[pos-1]));
	}
	printf("%lld\n",ans);
	return 0;
}