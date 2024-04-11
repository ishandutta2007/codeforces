#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int main(){
	ll n,k;
	cin>>n>>k;
	ll now=n;
	n+=k;
	n<<=1;
	for(ll i=1;i*i<=n;i++){
		if(n%i!=0){
			continue;
		}
		if((n/i)-i==3){
			cout<<now-i<<endl;
			break;
		}
	}
	return 0;
}
/*
(1+x)*x/2-(n-x)=k
(1+x)*x/2+x=n+k
(1+x)*x+2*x=2*n+2*k
x*(1+x+2)=2*n+2*k
x*(x+3)=2*(n+k)
*/