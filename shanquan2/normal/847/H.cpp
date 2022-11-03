#include<bits/stdc++.h>
using namespace std;

int n,a[100005],b[100005],c[100005];
long long f[100005],g[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		b[i]=max(a[i],b[i-1]+1);
		f[i]=f[i-1]+b[i]-a[i];
	}
	for(int i=n;i;i--){
		c[i]=max(a[i],c[i+1]+1);
		g[i]=g[i+1]+c[i]-a[i];
	}
	long long ans=1ll<<50;
	for(int i=1;i<=n;i++){
		long long tmp=f[i-1]+g[i+1]+max(max(b[i-1],c[i+1])+1,a[i])-a[i];
		if(tmp<ans)ans=tmp;
	}
	printf("%I64d\n",ans);
	return 0;
}