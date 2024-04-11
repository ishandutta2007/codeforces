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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll k, n;

pll A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	multiset<ll> ins, outs;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> A[i].Y >> A[i].X, outs.insert(A[i].Y);
	sort(A, A + n);
	ll sum = 0;	
	for (int i = 0; i < k; i++) {
		sum += *outs.rbegin();
		ins.insert(*outs.rbegin());
		outs.erase(outs.find(*outs.rbegin()));
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, A[i].X * sum);
		ll x = A[i].Y;
		if (outs.find(x) != outs.end()) outs.erase(outs.find(x));
		else {
			auto it = ins.find(x);
			if (it != ins.end()) {
				sum -= x;
				ins.erase(it);
				if (!outs.empty()) ins.insert(*outs.rbegin()), sum += *outs.rbegin(), outs.erase(outs.find(*outs.rbegin()));
			}
		}	
	}

	cout << ans << endl;
	return  0;
}