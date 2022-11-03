#include<bits/stdc++.h>
using namespace std;

const int M=1000000007;
int fexp(int x,int t){
	if(!t)return 1;
	int tmp=fexp(x,t>>1);tmp=1ll*tmp*tmp%M;
	return (t&1)?1ll*tmp*x%M:tmp;
}
int n,k,a[5005];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<=k;i++)a[i]=fexp(i,k);
	int ans=0,p=1;
	for(int i=0;i<=k&&i<=n;i++){
		ans=(ans+1ll*p*fexp(2,n-i)%M*a[0])%M;
		p=1ll*p*(n-i)%M*fexp(i+1,M-2)%M;
		for(int j=0;j<k-i;j++)a[j]=(a[j+1]-a[j]+M)%M;
	}
	printf("%d\n",ans);
	return 0;
}