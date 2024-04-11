#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin>>T;
	for (int tt=1; tt<=T; tt++) {
		ll n, m; cin>>n>>m;
		ll steps=0;

		while (n!=0) {
			steps+=n%m;
			n-=n%m;
			n/=m;
			steps++;
		}
		steps--;
		cout<<steps<<'\n';
	}

	return 0;
}