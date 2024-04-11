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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, C[MAXN], A[MAXN];

struct SegmentTree {
	ll sg[MAXN], lz[MAXN];

	void Push(int v) {
		lz[v << 1] += lz[v];
		lz[v << 1 | 1] += lz[v];
		sg[v] += lz[v];
		lz[v] = 0;
	}

	void Update(int v, int L, int R, int ql, int qr, ll val) {
		Push(v);
		if (qr < ql) return;
		if (ql == L && qr == R) {
			lz[v] += val;
			Push(v);
			return;
		}
		
		int mid = (L + R) >> 1;
		Update(v << 1, L, mid, ql, min(qr, mid), val);
		Update(v << 1 | 1, mid + 1, R, max(mid + 1, ql), qr, val);
		sg[v] = min(sg[v << 1], sg[v << 1 | 1]);
	}

	ll Query(int v, int L, int R, int ql, int qr) {
		Push(v);
		if (qr < ql) return INF;
		if (ql == L && qr == R) return sg[v];
		
		int mid = (L + R) >> 1;
		return min(Query(v << 1, L, mid, ql, min(qr, mid)), Query(v << 1 | 1, mid + 1, R, max(mid + 1, ql), qr));
	}

	void Update(int ql, int qr, ll val) {
		Update(1, 1, n, ql, qr, val);
	}

	ll Query(int ql, int qr) {
		return Query(1, 1, n, ql, qr);
	}

};

vector<pll> v;
SegmentTree sg1, sg2;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		v.push_back({0, 0});
		cin >> v.back().X >> v.back().Y;
	}

	sort(all(v));
	for (int i = 0; i < n; i++) {
		C[i + 1] = v[i].Y;
		A[i + 1] = v[i].X;
	}

	sg1.Update(n, n, C[n] + A[n]);
	sg2.Update(n, n, C[n]);

	for (int i = n - 1; i > 0; i--) {
		int tl = lower_bound(A + i + 1, A + n + 1, A[i] + C[i]) - A;
		sg1.Update(tl, n, -A[i]);
		sg2.Update(i, tl - 1, C[i]);

		ll ans = min(sg1.Query(tl, n), sg2.Query(i + 1, tl - 1));
		sg1.Update(i, i, ans);	
		sg2.Update(i, i, ans);	

		sg1.Update(tl, n, A[i]);
		sg2.Update(i, tl - 1, -C[i]);
		sg1.Update(i + 1, n, C[i]);
		sg2.Update(i + 1, n, C[i]);
		sg1.Update(i, i, A[i]);
	}

	cout << sg2.Query(1, 1) << endl;
	return 0;
}