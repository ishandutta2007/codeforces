#include <bits/stdc++.h>
using namespace std;
#define maxn 2200010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
struct th {
	int a[2];
	th() {a[0] = a[1] = 0;}
	th(int r) {
		a[0] = r, a[1] = 0;
	}
	th (int x, int y) {
		a[0] = x, a[1] = y;
	}
}p[maxn], r[maxn];
th u(th a, th b) {
	if (a.a[0] < b.a[0]) swap(a, b);
	return th(a.a[0], max(a.a[1], b.a[0]));
}
int a[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	int mxs = 21;
	for (int j = 0; j <= mxs; j++) {
		if (j == 0) {
			for (int i = n; i >= 1; i--)
				if (!r[a[i]].a[0]) r[a[i]].a[0] = i;
				else if (!r[a[i]].a[1]) r[a[i]].a[1] = i;
		}
		else {
			int qr = 1 << (j - 1);
			for (int i = 0; i < (1 << mxs); i++) {
				r[i] = p[i];
				if (!(i & qr))
					r[i] = u(r[i], p[i ^ qr]);
			}
		} 
		for (int k = 0; k < (1 << mxs); k++)
			p[k] = r[k];
	}
	int ans = 0;
	for (int i = 1; i <= n - 2; i++) {
		int nans = 0;
		for (int j = 20; j >= 0; j--)
			if (a[i] & (1 << j)) continue;
			else 
				if (p[nans | (1 << j)].a[1] > i) 
					nans |= (1 << j);
 		ans = max(nans | a[i], ans);
	}
	cout << ans << endl;
	return 0;
}