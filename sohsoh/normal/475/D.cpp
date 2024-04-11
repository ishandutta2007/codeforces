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

const ll MAXN = 1e6 + 3;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 18;	

map<int, ll> mp;
int n, A[MAXN], q, GCD[MAXN][LOG];

inline int Gcd(int L, int R) {
	int l = __lg(R - L + 1);
	return __gcd(GCD[L][l], GCD[R - (1 << l) + 1][l]);
}

inline pair<int, int> MaxInd(int tL, int L) {
	int R = n, g = Gcd(tL, L);
	while (L < R) {
		int mid = (L + R + 1) >> 1;
		if (Gcd(tL, mid) == g) L = mid;
		else R = mid - 1;
	}

	return {L, g};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i], GCD[i][0] = A[i];

	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) 
			GCD[i][j] = __gcd(GCD[i][j - 1], GCD[i + (1 << (j - 1))][j - 1]);
	}
	for (int L = 1; L <= n; L++) {
		int ind = L;
		while (ind <= n) {
			pair<int, int> p = MaxInd(L, ind);
			mp[p.Y] += p.X - ind + 1;
			ind = p.X + 1;
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << mp[x] << endl;
	}
	return 0;
}