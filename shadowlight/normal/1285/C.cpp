#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll x;
	cin >> x;
	ll res = x;
	ll ra = x, rb = 1;
	for (int i = 1; i <= sqrtl(x); i++) {
		if (x % i) continue;
		if (__gcd(x/i, (ll)i) != 1) continue;
		ll a = x / i, b = i;
		if (max(ra, rb) > max(a, b)) {
			ra = a, rb = b;
		}
	}
	cout << ra << " " << rb << "\n";
}