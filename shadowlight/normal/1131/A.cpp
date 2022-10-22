#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;
	if (w2 < w1) {
		swap(w1, w2);
		swap(h1, h2);
	} 
	ll res = 0;
	res += w1 + 2 * (h1 + h2) + w2;
	res += 4;
	if (w1 != w2) {
		res += w2 - w1;
	}
	cout << res << "\n";
}