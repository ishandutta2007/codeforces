#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	ll sum = 0LL;
	bool hasodd = false;
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		sum+=cur;
		if (cur%2==1) hasodd = true;
	}
	if (sum%2==1 || hasodd) cout << "First\n";
	else cout << "Second\n";
	// cin >> n;
	//
}