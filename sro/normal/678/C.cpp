#include <bits/stdc++.h>
using namespace std;

long long n,a,b,p,q;

long long gcd(long long a,long long b){
	return !b?a:gcd(b,a%b);
}

int main(){
	scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&p,&q);
	printf("%lld\n",n/a*p+n/b*q-n/(a*b/gcd(a,b))*min(p,q));
	return 0;
}