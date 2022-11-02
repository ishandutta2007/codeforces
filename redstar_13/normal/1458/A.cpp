#include <bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;

using INT = long long;
using pii = pair<int, int>;

INT a[200011];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	INT g = 0;
	for(int i=0; i<n; i++) cin >> a[i], g = __gcd(a[i], g);
	sort(a, a+n);
	INT h = 0;
	for(int i=0; i<n; i++) {
		h = __gcd(h, a[i] - a[0]);
	}
	
	for(int i=0; i<m; i++) {
		INT x;
		cin >> x;
		cout << __gcd(h, a[0] + x) << endl;
	}
}