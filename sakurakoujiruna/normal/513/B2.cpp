#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using ll = long long;

int main() {
	ios :: sync_with_stdio(false);
	int n; ll m; cin >> n >> m;
	m --;
	vector <int> vl, vr;
	for(int i = 1; i <= n; i ++)
		if(i == n || ((m >> (n - i - 1)) & 1 ^ 1))
			vl.pb(i);
		else
			vr.pb(i);
	reverse(vr.begin(), vr.end());
	for(int x : vl) cout << x << ' ';
	for(int x : vr) cout << x << ' ';
	cout << '\n';
	return 0;
}