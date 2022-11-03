#include<bits/stdc++.h>
using namespace std;

int n,x,y,a[2000005];
long long s[2000005],ans=1ll<<60;
int main(){
	scanf("%d%d%d",&n,&x,&y);
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		a[x]++;s[x]+=x;
	}
	for(int i=1;i<=2000000;i++)a[i]+=a[i-1],s[i]+=s[i-1];
	for(int i=2;i<=1000000;i++){
		long long tmp=0;
		for(int j=0;j<=1000000;j+=i){
			int k=j+i,l=max(1ll*j,(1ll*k*y-x)/y);
			tmp+=1ll*(a[l]-a[j])*x+(1ll*k*(a[k]-a[l])-(s[k]-s[l]))*y;
		}
		if(tmp<ans)ans=tmp;
	}
	printf("%I64d\n",ans);
	return 0;
}