#include<cstdio>
#include<iostream>
using namespace std;
int T;long long n,a;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%lld",&n);a=1;
		for(n*=2;n%2==0;n/=2) a*=2;
		if(n<2) printf("-1\n");
		else printf("%lld\n",min(a,n));
	}
	return 0;
}