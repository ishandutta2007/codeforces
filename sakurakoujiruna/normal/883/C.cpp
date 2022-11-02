#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

ll f, T, t0;
ll a1, t1, p1;
ll a2, t2, p2;
ll calc(ll u1, ll u2) {
	ll ut1 = min(u1 * a1, f);
	ll ut2 = min(u2 * a2, f - ut1);
	return (f - ut1 - ut2) * t0 + ut1 * t1 + ut2 * t2;
}

int main() {
	cin >> f >> T >> t0;
	cin >> a1 >> t1 >> p1;
	cin >> a2 >> t2 >> p2;
	
	if(f * min({t0, t1, t2}) > T)
		cout << "-1\n";
	else {
		ll ans = 1e18L;
		
		if(t1 > t2) {
			swap(a1, a2);
			swap(t1, t2);
			swap(p1, p2);
		}
		
		//for(int _ : {0, 1}) {
			for(ll i = 0; i <= (f + a1 - 1) / a1; i ++) {
				ll f2 = f - min(i * a1, f);
				ll lim2 = (f2 + a2 - 1) / a2;
				ll T2 = T - (f - f2) * t1;
				
				if(T2 < 0) continue;
				
				if(calc(i, 0) <= T)
					ans = min(ans, i * p1);
				if(calc(i, lim2) <= T)
					ans = min(ans, i * p1 + lim2 * p2);
				
				if(t2 < t0 && f2 * t0 >= T2) {
					ll den = a2 * (t0 - t2);
					ll x = (f2 * t0 - T2 + den - 1) / den;
					if(x > 0 && x < lim2 && calc(i, x) <= T)
						ans = min(ans, i * p1 + x * p2);
				}
			}
		
		//}
	
		cout << ans << '\n';
	}
		
	return 0;
}