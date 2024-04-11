#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second
using pii = pair <int, int>;

ll solve(vector <pii> va, vector <pii> vb, ll s, ll p) {
	ll all = p * s;
	ll r = 0;
	for(pii i : va) {
		r += i.fir * ll(i.sec);
		all -= i.sec;
	}
	all = all / s * s;
	sort(vb.begin(), vb.end());
	reverse(vb.begin(), vb.end());
	for(pii i : vb) {
		ll use = min(all, ll(i.sec));
		r += i.fir * use;
		all -= use;
	}
	return r;
}

int main() {
	int n, s; cin >> n >> s;
	
	vector <pii> va, vb;
	ll base = 0, all = 0;
	for(int i = 0; i < n; i ++) {
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		base += ll(t) * min(a, b);
		if(a > b)
			va.pb({a - b, t});
		else
			vb.pb({b - a, t});
		all += t;
	}
	
	cout << base + max(solve(va, vb, s, (all + s - 1) / s), solve(vb, va, s, (all + s - 1) / s)) << '\n';
	
	return 0;
}