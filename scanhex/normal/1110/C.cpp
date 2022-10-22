#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

int gcd(int a,int b){
	while(b){
		 a%=b,swap(a,b);
	}
	return a;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int C=27;
	vector<int>prec={0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401,};
	auto calc=[&](int a){
		int mx=0,mxi=-1;
		for(int b=1;b<a;++b)
			if(gcd(a&b,a^b)>=mx)
				mx=gcd(a&b,a^b),mxi=b;
		return mx;
	};
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int kek=1;
		int i=0;
		while(2*kek<=n)kek*=2,++i;
		int ans=-1;
		if(2*kek-1==n)
			ans=prec[i];
		else
			ans=2*kek-1;
//		assert(ans==calc(n));
		cout<<ans<<'\n';
	}
	return 0;
}