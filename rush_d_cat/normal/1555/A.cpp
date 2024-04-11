#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t; cin >> t;
	while (t --) {
		ll x; cin >> x;
		x = (x + 1) / 2;
		x = max(x, 3LL);
		cout << (5*x) << endl;
	}
}
/*
6 8 10
15 20 25

3,4,5,6,7,8



*/