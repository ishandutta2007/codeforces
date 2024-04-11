#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int T; cin>>T;
	while (T--) {
		ll n, a, b; cin>>n>>a>>b;
		ll t=0;
		if (n%2!=0) {
			t+=a;
		}
		n/=2;
		t+=min(2*a, b)*n;
		cout<<t<<endl;

	}
	return 0;
}