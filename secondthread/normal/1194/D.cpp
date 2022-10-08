#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while (T--) {
		int n, k; cin>>n>>k;
		bool wining=true;
		if (k%3!=0) {
			wining=n%3!=0;
		}
		else {
			n%=k+1;
			if (n%3!=0||n==k) wining=true;
			else wining=false;
		}
		cout<<(wining?"Alice":"Bob")<<'\n';

	}

	return 0;
}