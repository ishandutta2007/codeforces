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

const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;
const ll LOG = 64;

ll L, R, T[LOG];
bitset<LOG> LB, RB;

bitset<LOG> Build(int n, int k, bitset<LOG> BS) {
	bitset<LOG> ans;
	for (int i = 0; i < n; i++) ans[i] = BS[i % k];
	return ans;
}

inline ll solve(bitset<LOG> LB, bitset<LOG> RB) {
	memset(T, 0, sizeof T);
	int n = __lg(LB.to_ullong()) + 1;

	for (int k = 1; k < n; k++) {
		if (n % k) continue;
		
		bitset<LOG> LF, RF;
		for (int i = n - 1; i >= n - k; i--) LF[i - n + k] = LB[i], RF[i - n + k] = RB[i];

		T[k] += max(0ll, ll(RF.to_ullong()) - ll(LF.to_ullong()) - 1);
		bitset<LOG> BSL = Build(n, k, LF), BSR = Build(n, k, RF);
		if (LF != RF) {
			if (BSR.to_ullong() <= RB.to_ullong()) T[k]++;
			if (BSL.to_ullong() >= LB.to_ullong()) T[k]++;
		} else {
			if (BSR.to_ullong() <= RB.to_ullong() && BSR.to_ullong() >= LB.to_ullong()) T[k]++;
		}

		for (int i = 1; i < k; i++)
			if (k % i == 0) 
				T[k] -= T[i];
	}

	ll ans = 0;
	for (int i = 0; i < LOG; i++) ans += T[i];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> L >> R;
	LB = bitset<LOG>(L), RB = bitset<LOG>(R);

	ll ans = 0;
	while (LB.to_ullong() <= RB.to_ullong()) {
		int lb_size = __lg(LB.to_ullong()), rb_size = __lg(RB.to_ullong());
		if (lb_size == rb_size) {
			ans += solve(LB, RB);
			break;
		} else {
			bitset<LOG> tmp((1ll << (lb_size + 1)) - 1);
			ans += solve(LB, tmp);
			LB = bitset<LOG>((1ll << (lb_size + 1)));
		}
	}

	cout << ans << endl;
	return 0;
}