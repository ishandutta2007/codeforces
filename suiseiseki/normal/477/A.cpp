#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Mod 1000000007
int main(){
	ll a,b;
	ll sum;
	while(cin>>a>>b){
		sum=0;
		for(ll i=1;i<=a;i++){
			sum+=((i*b)%Mod+1)%Mod;
			sum%=Mod;
		}
		ll ans=(((b-1)*b)/2)%Mod;
		cout<<sum*ans%Mod<<endl;
	}
	return 0;
}