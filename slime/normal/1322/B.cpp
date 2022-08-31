#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int n;
int a[maxn];
int b[maxn];
int cal(int a) {
	if (b[n] <= a) return n;
	int pl = lower_bound(b + 1, b + n + 1, a + 1) - b - 1;
	return pl;
}
int cal(int l, int r) {
	return cal(r) - cal(l - 1);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	ll ans = 0;
	for (int i = 0; i < 25; i++) {
		for (int j = 1; j <= n; j++)
			b[j] = a[j] % (1 << (i + 1));
		sort(b + 1, b + n + 1);
		ll c = 0;
		int dv = (1 << i);
		for (int i = 1; i <= n; i++)
			c += cal(dv - b[i], 2 * dv - 1 - b[i]), 
			c += cal(3 * dv - b[i], 4 * dv - 1 - b[i]);
		for (int i = 1; i <= n; i++) 
			if ((b[i] * 2) & dv) c--;
		c /= 2;
		if (c & 1) ans += dv;
	}
	cout << ans << endl;
	return 0;
}