#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll fcnt = 0, sum = 0, ksum = 0, k = 0;
map<ll, ll> ins, outs;

ll solve() {
	ll tp, d;
       	cin >> tp >> d;
	if (d < 0) {
		d *= -1;
		sum -= d;
		if (tp == 0) {
			if (outs.find(d) != outs.end()) outs.erase(d);
			else {
				ins.erase(d);
				ksum -= d;
				fcnt--;
				if (!outs.empty()) {
					pll x = *outs.rbegin();
					outs.erase(x.X);
					ins.insert(x);
					if (x.Y == 0) fcnt++;
					ksum += x.X;
				}
			}
		} else {
			k--;
			if (ins.find(d) != ins.end()) {
				ins.erase(d);
				ksum -= d;
			} else {
				outs.erase(d);
				if (!ins.empty()) {
					pll x = *ins.begin();
					if (x.Y == 0) fcnt--;
					ksum -= x.X;
					ins.erase(x.X);
					outs.insert(x);
				}
			}	
		}
	} else {
		sum += d;
		if (tp == 0) {
			if (!ins.empty() && (ins.begin() -> X) < d) {
				pll x = *ins.begin();	
				ksum -= x.X;
				ksum += d;
				ins.erase(x.X);
				outs.insert(x);
				ins.insert({d, tp});
				fcnt++;
				if (x.Y == 0) fcnt--;
			} else outs.insert({d, tp});
		  } else {
		  	k++;
			outs.insert({d, tp});
			pll x = *outs.rbegin();
			ins.insert(x);
			outs.erase(x.X);
			ksum += x.X;
			if (x.Y == 0) fcnt++;
		  }
	}
	
	if (ins.size() == 0) cout << sum << endl;
	else if (fcnt) cout << ksum + sum << endl;
	else {
		ll ans = sum + ksum;
		ans -= ins.begin() -> X;
		if (!outs.empty()) ans += outs.rbegin() -> X;
		cout << ans << endl;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	while (n--) solve();
	return 0;
}