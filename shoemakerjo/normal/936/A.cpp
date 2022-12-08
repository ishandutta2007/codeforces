#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll k, d, t;
	cin >> k >> d >> t;
	double ans = 0.0;
	ll mult = k/d;
	if (d*mult != k) mult+=1LL;
	double cyc = mult*d;
	double otime = k;
	double oftim = mult*d-k;
	double p1 = otime/(t+0.0);
	double p2 = oftim/(t*2.0);
	// cout << p1 << " - " << p2 << endl;
	ll amount = (ll) floor(1.0/(p1+p2));
	double left = 1.0 - (p1+p2)*amount;
	ans += amount*(cyc);
	// cout << "here   " << ans << " " << left << endl;
	if (left <= p1) {
		// cout << (left/p1) << endl;
		ans += otime*(left/p1);
	}
	else {
		left -= p1;
		ans += k;
		ans += oftim*(left/p2); 
	}
	cout << fixed << setprecision(15) << ans << endl;
	cin >> k;
	
}