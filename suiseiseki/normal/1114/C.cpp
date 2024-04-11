#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int main(){
	ll n,b;
	cin>>n>>b;
	ll maxn;
	ll num=0;
	ll now=0;
	ll ans=(1ll<<60);
	ll _n;
	for(ll i=2;i*i<=b;i++){
		if(b%i==0){
			maxn=i;
			num=0;
			while(b%i==0){
				b/=i;
				num++;
			}
			_n=n;
			now=0;
			while(_n){
				now+=_n/=maxn;
			}
			ans=min(ans,now/num);
		}
	}
	if(b>1){
		maxn=b;
		num=1;
		_n=n;
		now=0;
		while(_n){
			now+=_n/=maxn;
		}
		ans=min(ans,now/num);
	}
	cout<<ans<<endl;
	return 0;
}