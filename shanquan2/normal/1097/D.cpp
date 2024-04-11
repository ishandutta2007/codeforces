#include<bits/stdc++.h>
using namespace std;

const int M=1000000007;
long long n,k,m,f[55][10005],iv[65];
int fexp(int x,int t){
	if(!t)return 1;
	int tmp=fexp(x,t>>1);tmp=1ll*tmp*tmp%M;
	return (t&1)?tmp*1ll*x%M:tmp;
}
long long calc(long long x,int t){
	x%=M;
	f[0][0]=1;
	for(int i=1;i<=t;i++)f[i][0]=f[i-1][0]*x%M;
	for(int i=1;i<=k;i++){
		long long s=0;
		for(int j=0;j<=t;j++){
			s=(s+f[j][i-1])%M;
			f[j][i]=s*iv[j+1]%M;
		}
	}
//	printf("%lld %d\n",x,t);
//	printf("%lld\n",f[t][k]);
	return f[t][k];
}
int main(){
	for(int i=1;i<=60;i++)iv[i]=fexp(i,M-2);
	cin>>n>>k;m=n;
	int ans=1;
	for(int i=2;1ll*i*i<=m;i++){
		int s=0;
		while(n%i==0)n/=i,s++;
		if(s)ans=ans*1ll*calc(i,s)%M;
	}
	if(n>1)ans=ans*1ll*calc(n,1)%M;
	printf("%d\n",ans);
	return 0;
}