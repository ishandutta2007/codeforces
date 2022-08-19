#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
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
	int x, y;
	th(int a, int b) {
		x = a, y = b;
	}
	bool operator < (const th &r)const {
		if (x != r.x) return x < r.x;
		return y < r.y;
	}
};
multiset<int> r1, r2;
#define iter multiset<int>::iterator
ll work(vector<th> r) {
	int n = r.size();
	r1.clear(), r2.clear();
	sort(r.begin(), r.end());
	for (int i = 0; i < n; i++)
		r2.insert(r[i].y);
	ll nans = 0;
	for (int i = 0; i < n; i++) {
		r2.erase(r2.find(r[i].y)), 
		r1.insert(r[i].y);
		if (r1.empty() || r2.empty()) continue;
		int dv = (r[i + 1].x - r[i].x) / 2;
		int l1 = max(*r1.begin(), *r2.begin()) + 1;
		int rr = min(*(--r1.end()), *(--r2.end())) - 1;
		if (l1 > rr) continue;
		nans += 1ll * dv * ((rr - l1) / 2 + 1);
	}
	return nans;
}
int main() {
	int n;
	cin >> n;
	vector<th> r1, r2;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		th r = th(a + b, a - b);
		if ((a + b) & 1) r1.pb(r);
		else r2.pb(r);
	}
	ll ans = work(r1) + work(r2);
	cout << ans << endl;
	return 0;
}