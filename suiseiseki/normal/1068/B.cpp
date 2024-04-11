#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int main(){
	ll n;
	cin>>n;
	ll ans=1;
	ll now;
	for(ll i=2;i*i<=n;i++){
		now=0;
		while(n%i==0){
			n/=i;
			now++;
		}
		ans*=(now+1);
	}
	if(n>1){
		ans<<=1;
	}
	cout<<ans<<endl;
	return 0;
}