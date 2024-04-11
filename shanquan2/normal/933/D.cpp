#include<bits/stdc++.h>
using namespace std;

const int M=1000000007;
long long m,n,ans;
int fexp(int x,int t){
	if(!t)return 1;
	int tmp=fexp(x,t>>1);tmp=1ll*tmp*tmp%M;
	return (t&1)?1ll*tmp*x%M:tmp;
}
int main(){
	scanf("%I64d",&m);
	n=m%M;
	long long k=1000000;
	long long inv3=fexp(3,M-2),inv15=fexp(15,M-2),inv21=fexp(21,M-2),inv6=fexp(6,M-2);
	for(int i=0;1ll*i*i<=m;i++){
		while(k>=0&&1ll*k*k+1ll*i*i>m)k--;
		long long x=i;
		long long tmp=0;
		tmp=(n*(2 + 3*n + n*n%M)%M + x*x%M*((4 + 3*n) + x*x%M*((-3*(2 + n)%M+M + 2*x*x)%M)%M)%M)%M*(2*k+1)%M
		    +(4 + 3*n +6*x*x%M*((- (2 + n)%M+ x*x+M)%M)%M)%M*k%M*(k+1)%M*(2*k+1)%M*inv3%M
			+(-3*(2+n)%M + 6*x*x+M)%M*k%M*(1 + k)%M*(1 + 2*k)%M*(M-1 + 3*k + 3*k*k%M)%M*inv15%M
			+2* k*(1 + k)%M*(1 + 2*k)%M*(1 - 3*k%M+M + 6*k*k%M*k%M + 3*k*k%M*k%M*k%M)%M*inv21%M;
//		printf("%d %d %d\n",i,k,2* k*(1 + k)%M*(1 + 2*k)%M*(1 - 3*k%M+M + 6*k*k%M*k%M + 3*k*k%M*k%M*k%M)%M*inv21%M);
		if(i==0)ans=(ans+tmp)%M;
		else ans=(ans+2*tmp)%M;
	}
	printf("%I64d\n",ans*inv6%M);
	return 0;
}