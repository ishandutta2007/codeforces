#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int main(){
	ll n,p,w,d;
	cin>>n>>p>>w>>d;
	for(ll i=0;i<w;i++){
		if((p-i*d)%w==0){
			ll j=(p-i*d)/w;
			if(j<0||i+j>n){
				puts("-1");
				return 0;
			}
			cout<<j<<' '<<i<<' '<<n-i-j<<endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}