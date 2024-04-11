// \_()_/
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

const ll MAXN = 4e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, sg[MAXN], sg_r[MAXN], cnt1[MAXN], q;
bool lz[MAXN], A[MAXN];

void Build(int v, int L, int R) {
	if (L == R) {
		cnt1[v] = A[L];
		sg[v] = sg_r[v] = 1;
		return;
	}

	int mid = (L + R) >> 1;
	Build(v << 1, L, mid);
	Build(v << 1 | 1, mid + 1, R);
	sg[v] = max(sg[v << 1] + cnt1[v << 1 | 1], sg[v << 1 | 1] + (mid - L + 1) - cnt1[v << 1]);
	sg_r[v] = max(sg_r[v << 1 | 1] + cnt1[v << 1], sg_r[v << 1] + (R - mid) - cnt1[v << 1 | 1]);
	cnt1[v] = cnt1[v << 1] + cnt1[v << 1 | 1];
}

void Push(int v, int L, int R) {
	if (lz[v]) {
		cnt1[v] = R - L + 1 - cnt1[v];
		swap(sg[v], sg_r[v]);
		if (L != R) {
			lz[v << 1] ^= 1;
			lz[v << 1 | 1] ^= 1;
		}

		lz[v] = false;
	}
}

void Update(int v, int L, int R, int QL, int QR) {
	Push(v, L, R);
	if (QL > QR) return;
	if (QL == L && QR == R) {
		lz[v] ^= 1;
		Push(v, L, R);
		return;
	}

	int mid = (L + R) >> 1;
	Update(v << 1, L, mid, QL, min(QR, mid));
	Update(v << 1 | 1, mid + 1, R, max(QL, mid + 1), QR);
	
	sg[v] = max(sg[v << 1] + cnt1[v << 1 | 1], sg[v << 1 | 1] + (mid - L + 1) - cnt1[v << 1]);
	sg_r[v] = max(sg_r[v << 1 | 1] + cnt1[v << 1], sg_r[v << 1] + (R - mid) - cnt1[v << 1 | 1]);
	cnt1[v] = cnt1[v << 1] + cnt1[v << 1 | 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		A[i] = (c == '7');
	}

	Build(1, 1, n);
	while (q--) {
		string s;
		cin >> s;
		if (s == "count") cout << sg[1] << endl;
		else {
			int L, R;
			cin >> L >> R;
			Update(1, 1, n, L, R);
		}
	}
	return 0;
}