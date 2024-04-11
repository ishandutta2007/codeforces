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
 
const ll MAXN = 3e5 + 10;
const ll INF = 1e6;
const ll INF2 = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll sg[4 * MAXN] = {0}, lz[4 * MAXN] = {0}, P[MAXN], Q[MAXN], ind[MAXN];

void push(ll v, ll ss, ll se) {
	if (lz[v] != 0) {
		sg[v] += lz[v];
		if (ss != se) {
			lz[2 * v + 1] += lz[v];
			lz[2 * v + 2] += lz[v];
		}
	}

	lz[v] = 0;
}

void update(ll v, ll ss, ll se, ll us, ll ue, ll diff) {
	push(v, ss, se);
	if (ss > se || ss > ue || se < us) return; 
	
	if (ss >= us && se <= ue) {
		sg[v] += diff;
		
		if (ss != se) {
			lz[2 * v + 1] += diff;
			lz[2 * v + 2] += diff;
		}

		return;
	}

	ll mid = (ss + se) / 2;
	update(2 * v + 1, ss, mid, us, ue, diff);
	update(2 * v + 2, mid + 1, se, us, ue, diff);

	sg[v] = min(sg[2 * v + 1], sg[2 * v + 2]);
}

ll RMQ(ll v, ll ss, ll se, ll qs, ll qe) {
	push(v, ss, se);	
	if (ss > se || ss > qe || se < qs) return INF2;
	if (ss >= qs && se <= qe) return sg[v];

	ll mid = (ss + se) / 2;
	return min(RMQ(2 * v + 1, ss, mid, qs, qe), RMQ(2 * v + 2, mid + 1, se, qs, qe));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;


	for (int i = 1; i <= n; i++) cin >> P[i], ind[P[i]] = i;
	for (int i = 1; i <= n; i++) cin >> Q[i];
	for (int i = 0; i <= n + 2; i++) update(0, 0, MAXN, i, i, INF);
	
	ll ans = n;
	cout << ans << sep;	

	for (int i = 1; i <= n - 1; i++) {
		update(0, 0, MAXN, 0, Q[i], 1);
		
		while (ans > 0) {
			update(0, 0, MAXN, ind[ans], ind[ans], -1 * INF);
			update(0, 0, MAXN, 0, ind[ans], -1);
			if (RMQ(0, 0, MAXN, 1, n) >= 0) ans--;
			else {
				update(0, 0, MAXN, ind[ans], ind[ans], INF);
				update(0, 0, MAXN, 0, ind[ans], 1);
				break;
			}
		}	

		cout << ans << sep;
	}

	cout << endl;
	return 0;
}