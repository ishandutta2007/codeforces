
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int a, b; cin>>a>>b;
	int mod=998244353;
	ll ans=1;
	for (int i=0; i<a+b; i++) {
		ans*=2;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}