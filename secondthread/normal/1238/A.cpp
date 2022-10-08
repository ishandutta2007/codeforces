#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int T; cin>>T;
	for (int tt=0; tt<T; tt++) {
		ll a, b; cin>>a>>b;
		if (abs(a-b)==1) {
			cout<<"NO\n";
		}
		else {
			cout<<"YES\n";
		}
	}
	return 0;
}