#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
ll n,t,x,dd,mx,h,d;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>x;
		dd=0,mx=0;
		for(ll i=0;i<n;i++){
			cin>>d>>h;
			dd=max(dd,d-h);
			mx=max(mx,d);
		}
		if(mx>=x){
			puts("1");
			continue;
		}
		if(dd==0){
			puts("-1");
			continue;
		}
		x-=mx;
		cout<<(x+dd-1)/dd+1<<endl;
	}
	return 0;
}