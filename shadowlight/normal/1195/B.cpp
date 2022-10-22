#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	ll now = 0, sh = 1;
	ll res = 0;
	while (now < k || res + (now - k) != n) {
		res++;
		now += sh++;
	}
	//cout << now << " " << k << "\n";
	cout << now - k << "\n";
}