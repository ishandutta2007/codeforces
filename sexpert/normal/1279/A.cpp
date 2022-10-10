#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		ll a, b, c;
		cin >> a >> b >> c;
		ll m = max({a,b,c});
		if(2*m - 1 > a + b + c)
			cout << "No\n";
		else
			cout << "Yes\n";
	}
}