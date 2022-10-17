#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int main(){
	ll n,m,k,l;
	cin>>n>>m>>k>>l;
	if(m>n||k+l>n){
		puts("-1");
		return 0;
	}
	ll ans=(k+l)/m;
	ans+=(k+l)%m?1:0;
	if(ans*m>n){
		puts("-1");
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}