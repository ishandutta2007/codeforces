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
const ll MOD = 777777777; // 998244353; // 1e9 + 9;

int A[MAXN], n, q, M[4][4];
ll sg[MAXN][4][4];

inline void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
}

void Update(int v, int L, int R, int ind) {
	if (R < L) return;
	if (L == R) {
		if (A[L] == 0) sg[v][1][1] = sg[v][2][2] = sg[v][3][3] = 1;
		else {
			sg[v][1][1] = sg[v][2][2] = sg[v][3][3] = 0;
			sg[v][A[L]][A[L]] = 1;
		}
		
		return;
	}

	int mid = (L + R) >> 1;
	if (ind <= mid) Update(v << 1, L, mid, ind);
	else Update(v << 1 | 1, mid + 1, R, ind);

	for (int s = 1; s <= 3; s++)
		for (int e = 1; e <= 3; e++)
			sg[v][s][e] = 0;
	for (int s1 = 1; s1 <= 3; s1++) 
		for (int e1 = 1; e1 <= 3; e1++) 
			for (int s2 = 1; s2 <= 3; s2++) 
				for (int e2 = 1; e2 <= 3; e2++)
					mkey(sg[v][s1][e2] += sg[v << 1][s1][e1] * sg[v << 1 | 1][s2][e2] * M[e1][s2] % MOD);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= 3; i++) 
		for (int j = 1; j <= 3; j++)
			cin >> M[i][j];
	for (int i = 1; i <= n; i++) Update(1, 1, n, i);
	
	while (q--) {
		int ind, x;
		cin >> ind >> x;
		A[ind] = x;
		Update(1, 1, n, ind);
		ll ans = 0;
		for (int s = 1; s <= 3; s++) 
			for (int e = 1; e <= 3; e++)
				mkey(ans += sg[1][s][e]);
		
		cout << ans << endl;	
	}
	return 0;
}