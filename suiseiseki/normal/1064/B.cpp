#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
ll x,ans;
void work(){
	ans=1ll;
	cin>>x;
	while(x){
		if((x&1ll)==1ll){
			ans<<=1;
		}
		x>>=1;
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		work();
	}
	return 0;
}