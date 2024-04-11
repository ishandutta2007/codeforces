#include<cstdio>
#include<iostream>
using namespace std;
int T;long long n,k,p;
long long calc(long long i){
	if(i==1) return k*(k+1)/2;
	long long p=calc((i-1)/k+1),l=(i-1)/k*(k*k+1)+(i-1-(i-1)/k*k)*k+1;
	return (2*l+k-1)*k/2+max(0ll,l+k-max(l,p));
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%lld%lld",&n,&k);
		p=calc((n-1)/(k*k+1)+1);
		if(n==p) printf("%lld\n",((n-1)/(k*k+1)+1)*(k+1));
		else
			n-=(n>=p),
			printf("%lld\n",(n-1)/(k*k+1)*k*k+((n-1)/(k*k+1)*k+(n-(n-1)/(k*k+1)*(k*k+1)-1)/k)+n-(n-1)/(k*k+1)*(k*k+1));
	}
	return 0;
}