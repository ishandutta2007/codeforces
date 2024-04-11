#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef double ld;
typedef complex<ld> point;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 4e6 + 10;
const ld PI = acos(-1);

int n, m, rev[MAXN], F[MAXN];
bool B[MAXN];
point A[MAXN];

inline void FFT(point* A, int n, bool inv) {
	int lg = __builtin_ctz(n);
	for (int i = 1; i < n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
		if (rev[i] < i) swap(A[i], A[rev[i]]);
	}

	for (int len = 1; len < n; len <<= 1) {
		ld ang = (inv ? -1 : 1) * PI / len;
		point wn(cos(ang), sin(ang));
	
		for (int i = 0; i < n; i += len * 2) {
			point w = 1;
			for (int j = i; j < i + len; j++) {
				point x = A[j], y = w * A[j + len];
				A[j] = x + y;
				A[j + len] = x - y;
				w *= wn;
			}
		}
	}

	if (inv)
		for (int i = 0; i < n; i++)
			A[i] /= n;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		B[x] = true;
		A[x] = 1;
	}

	int tn = (m + 3) * 2;
	n = 1;
	while (n < tn) n *= 2;

	FFT(A, n, false);
	for (int i = 0; i < n; i++)
		A[i] *= A[i];
	FFT(A, n, true);

	vector<int> ans;
	for (int i = 0; i <= m; i++) {
		int c = round(A[i].real());
		if (c > 0 && !B[i]) return cout << "NO" << endl, 0;
		if (c == 0 && B[i]) ans.push_back(i);
	}

	cout << "YES" << endl << ans.size() << endl;
	for (int e : ans)
		cout << e << sep;
	cout << endl;
	return 0;
}