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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 21;

vector<int> P[MAXN];
int A[MAXN], n, q, R[MAXN][LOG], ind[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 2; i < MAXN; i++)
		if (P[i].empty())
			for (int j = i; j < MAXN; j += i)
				P[j].push_back(i);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	R[n + 1][0] = n + 1;
	for (int i = n; i > 0; i--) {
		R[i][0] = R[i + 1][0];
		for (int e : P[A[i]]) {
			if (ind[e]) R[i][0] = min(R[i][0], ind[e]);
			ind[e] = i;
		}
	}
	
	for (int i = 1; i < LOG; i++)
		for (int j = 1; j <= n + 1; j++)
			R[j][i] = R[R[j][i - 1]][i - 1];

	while (q--) {
		int L, tR;
		cin >> L >> tR;
		int ans = 0;

		for (int i = LOG - 1; i >= 0; i--)
			if (R[L][i] <= tR)
				ans += (1 << i), L = R[L][i];
		cout << ans + 1 << endl;
	}
	return 0;
}