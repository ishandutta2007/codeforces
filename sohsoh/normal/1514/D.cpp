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
const ll T = 30;

vector<int> pos[MAXN];
int A[MAXN], n, q;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int Cnt(int L, int R, int x) {
	return upper_bound(all(pos[x]), R) - lower_bound(all(pos[x]), L);
}

inline int Maj(int L, int R) {
	int ind = rng() % (R - L + 1) + L;
	if (Cnt(L, R, A[ind]) > (R - L + 2) / 2) return A[ind];
	return 0;	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		pos[A[i]].push_back(i);
	}

	while (q--) {
		int L, R;
		cin >> L >> R;
		int m = 0;
		for (int i = 0; i < T; i++) m = max(m, Maj(L, R));
		if (m == 0) {
			cout << 1 << endl;
			continue;
		}

		int cnt = Cnt(L, R, m), rem = R - L + 1 - cnt;
		cout << max(cnt - rem, 1) << endl;
	}
	return 0;
}