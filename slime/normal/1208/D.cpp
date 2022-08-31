#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
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
ll d[maxn];
int lb(int x) {
	return x & -x;
}
void ch(int pl, int num) {
	while (pl < maxn)
		d[pl] += num, 
		pl += lb(pl);
}
ll q(int pl) {
	ll ans = 0;
	while (pl)
		ans += d[pl], 
		pl -= lb(pl);
	return ans;
}
ll rr[maxn];
int p[maxn];
set<int> s;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		ch(i + 1, i),
		scanf("%lld", &rr[i]), 
		s.insert(i);
	for (int i = n; i >= 1; i--) {
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (q(mid) >= rr[i]) r = mid;
			else l = mid + 1;
		}
		p[i] = *s.lower_bound(l);
		s.erase(p[i]);
		ch(p[i] + 1, -p[i]);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", p[i]);
	return 0;
}