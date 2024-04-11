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

const ll MAXN = 4e7 + 10;
const ll LOG = 34;

int C[MAXN][2], n, sz = 1, cnt[MAXN];
ll k, A[MAXN / 10];

inline void Insert(ll x) {
	int node = 1;
	cnt[1]++;
	for (int i = LOG - 1; i >= 0; i--) {
		if (x & (1ll << i)) {
			if (!C[node][1]) C[node][1] = ++sz;	
			node = C[node][1];
		} else {
			if (!C[node][0]) C[node][0] = ++sz;
			node = C[node][0];
		}
		
		cnt[node]++;
	}

}

inline ll Find(ll x) {
	ll ans = 0;
	int node = 1;
	
	for (int i = LOG - 1; i >= 0; i--) {
		int ind = (x & (1ll << i)) != 0;
		if (k & (1ll << i)) node = C[node][1 - ind];
		else {
			ans += cnt[C[node][1 - ind]];
			node = C[node][ind];
		}

		if (node == 0) return ans;
	}
	
	ans += cnt[node];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	ll ps = 0, ans = 0;
	Insert(0);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		ps ^= A[i];
		ans += Find(ps);
		Insert(ps);
	}

	cout << ans << endl;
	return 0;
}