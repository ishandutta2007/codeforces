#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
struct th {
	int l, r, cnt;
	th() {
		l = maxn, r = 0, cnt = 0;
	}
	bool operator < (const th &s) const{
		return l < s.l;
	}
}p[maxn];
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		p[a].l = min(i, p[a].l), p[a].cnt++;
		p[a].r = i;
	}
	sort(p, p + maxn);
	int ans = 0;
	for (int i = 0; i < maxn; ) {
		if (p[i].l == maxn) break;
		int rr = p[i].r, mx = 0;
		int j = i;
	//	cout << i << endl;
		while (j < maxn && p[j].l <= rr) {
			mx = max(mx, p[j].cnt), 
			rr = max(rr, p[j].r),
			j++;
		}
		ans += mx;
		i = j;
	}
	cout << n - ans << endl;
	return 0;
}