#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a;
		a--;
		int s=0,ans=1;
		for(int i=2;s<a;++i){
			s+=i;
			ans=i;
		}
		if(s==a+1)ans++;
		printf("%lld\n",ans);
	}
	return 0;
}