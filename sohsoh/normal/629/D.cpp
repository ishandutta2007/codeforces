// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const long double PI = 3.14159265359;

ll n, sg[MAXN], V[MAXN];
vector<ll> V_vec;

void Update(int ind, ll val, int L = 1, int R = n, int v = 1) {
	if (L == R) sg[v] = max(sg[v], val);
	else {
		int mid = (L + R) >> 1;
		if (ind <= mid) Update(ind, val, L, mid, v << 1);
		else Update(ind, val, mid + 1, R, v << 1 | 1);
		sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
	}
}

ll Query(int QL, int QR, int L = 1, int R = n, int v = 1) {
	if (QR < L || QL > R || QL > QR) return 0;
	if (QL <= L && QR >= R) return sg[v];

	int mid = (L + R) >> 1;
	return max(Query(QL, QR, L, mid, v << 1), 
			Query(QL, QR, mid + 1, R, v << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll r, h;
		cin >> r >> h;
		V[i] = r * r * h;
		V_vec.push_back(V[i]);
	}

	sort(all(V_vec));
	for (int i = 1; i <= n; i++) {
		int ind = lower_bound(all(V_vec), V[i]) - V_vec.begin() + 1;
		ll ans = V[i] + Query(1, ind - 1);
		Update(ind, ans);
	}

	cout << setprecision(10) << fixed << Query(1, n) * PI << endl;
	return 0;
}