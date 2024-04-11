#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b, c; cin>>a>>b>>c;
	if (c==0) {
	if (a==b) cout<<a+b<<endl;
	if (a<b) cout<<(a+a+1)<<endl;
	if (b<a) cout<<(b+b+1)<<endl;
	}
	else {
		ll ans=2*c;
		if (a==b) ans+=a+b;
		if (a<b) ans+=a+a+1;
		if (b<a) ans+=b+b+1;
		cout<<ans<<endl;
	}

	return 0;
}