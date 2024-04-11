#include <cstdio>
#include <iostream>////
using namespace std;
#define ll long long
ll a[500005];
template<typename Elem>
Elem ab(Elem a){
	return a<0?-a:a;
}
ll mx(ll a,ll b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	ll sum=0;
	int up=0,down=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=ab(a[i]);
		if(a[i]>=0){
			up++;
		}
		else{
			down++;
		}
	}
	if(n==1){
		cout<<a[1]<<endl;
		return 0;
	}
	ll ans=0;
	if(up>0&&down>0){
		cout<<sum<<endl;
	}
	else{
		for(int i=2;i<=n;i++){
			ans=mx(ans,sum-ab(a[i])-ab(a[i-1])+ab(a[i]-a[i-1]));
		}
		cout<<ans<<endl;
	}
	return 0;
}