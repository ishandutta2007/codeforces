#include<bits/stdc++.h>
#define M 1000000007
using namespace std;

int fexp(int x,int t){
	if(!t)return 1;
	int tmp=fexp(x,t>>1);
	tmp=1ll*tmp*tmp%M;
	return (t&1)?1ll*tmp*x%M:tmp;
}
int n,k,a[5005],f[5005];
int main(){
	scanf("%d%d",&n,&k);
	f[0]=1;
	long long t=1;
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		t=t*x%M;
		for(int j=i+1;j>=0;j--)if(j)f[j]=(1ll*f[j]*x%M-f[j-1]+M)%M;else f[j]=1ll*f[j]*x%M;
	}
	int g=fexp(n,M-2);
	long long ans=0,p=1;
	for(int i=0;i<=n;i++){
		(ans+=1ll*p*f[i]%M)%=M;
		p=p*g%M*(k-i)%M;
	}
	printf("%lld\n",(t-ans+M)%M);
	return 0;
}