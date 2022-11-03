#include<bits/stdc++.h>
using namespace std;

int q;
long long n,x;
long long calc(long long n,long long x){
	if(x&1)return (x+1)/2;
	long long t=n/2;
	if(n%2==0){
		return t+calc(t,x/2);
	}else{
		if(x==n)return t+1;
		return t+calc(t+1,1+x/2);
	}
}
int main(){
	scanf("%lld%d",&n,&q);
	while(q--){
		scanf("%lld",&x);
		printf("%lld\n",calc(n,x));
	}
	return 0;
}