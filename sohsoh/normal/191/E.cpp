// Sohsoh84 :)))
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tree<pll, null_type, less<pll>, rb_tree_tag,
       	tree_order_statistics_node_update> ordered_set;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;
const ll INF = 1e15;

ll A[MAXN], ps[MAXN], n, k;

inline ll Ans(ll c) {
	ll ans = 0;
	ordered_set st;

	for (int i = 1; i <= n; i++) {
		st.insert({ps[i - 1], i});
		ans += st.order_of_key({ps[i] - c, INF});
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		ps[i] = ps[i - 1] + A[i];
	}

	ll L = -INF, R = INF;
	while (L < R) {
		ll mid = (L + R + 1) >> 1;
		if (Ans(mid) >= k) L = mid;
		else R = mid - 1;
	}

	cout << L << endl;
	return 0;
}