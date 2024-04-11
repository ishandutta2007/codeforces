#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		cout << (__gcd(a, b) > 1 ? "Infinite\n" : "Finite\n");
	}
}