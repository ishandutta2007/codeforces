#include <bits/stdc++.h>

using namespace std;
#define ll long long

string a, b;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> a >> b;
	ll num1c = 0LL; //was a 1 in a, swapping to 0 changes things
	ll numoc = 0LL; //was a 0 in a, swapping to 1 changes things
	ll numones = 0LL;
	ll numzeros = 0LL;
	for (int i = 0; i < n; i++) {
		if (a[i] == '1') {
			if (b[i] == '0') num1c += 1LL;
			numones+= 1LL;
		}
		else {
			if (b[i] == '0') numoc += 1LL;
			numzeros += 1LL;
		}
	}
	ll ans = 0LL;
	ans += num1c * numzeros;
	ans += numoc * numones;
	ans -= num1c * numoc;
	cout << ans << endl;
}