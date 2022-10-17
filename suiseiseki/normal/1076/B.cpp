#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int main(){
	ll n;
	cin>>n;
	ll ans=-1;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ans=i;
			break;
		}
	}
	if(ans==-1){
		ans=n;
	}
	cout<<(n-ans)/2+1<<endl;
	return 0;
}
/////////////////////