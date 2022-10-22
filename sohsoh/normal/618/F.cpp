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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, A[MAXN], B[MAXN], K[MAXN], D[MAXN], ps1 = 0, ps2 = 0, s1 = 0, s2 = 0, ind[MAXN];
bool sp = false;

inline void print(int L, int R) {
	cout << R - L + 1 << endl;
	for (int i = L; i <= R; i++) cout << i << sep;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i], s1 += A[i];
	for (int i = 1; i <= n; i++) cin >> B[i], s2 += B[i];
	if (s1 > s2) swap(A, B), sp = true;

	int k = 0;
	for (int i = 1; i <= n; i++) {
		ps1 += A[i];
		while (ps2 < ps1) k++, ps2 += B[k];
	       	K[i] = k;
		D[i] = ps2 - ps1;
		if (D[i] == 0) {
			if (sp) print(1, k), print(1, i);
			else print(1, i), print(1, k);
			return 0;
		}	
	}

	for (int i = 1; i <= n; i++) {
		if (ind[D[i]]) {
			if (sp) print(K[ind[D[i]]] + 1, K[i]), print(ind[D[i]] + 1, i);
			else print(ind[D[i]] + 1, i), print(K[ind[D[i]]] + 1, K[i]);
			return 0;
		}

		ind[D[i]] = i;
	}
	return 0;
}