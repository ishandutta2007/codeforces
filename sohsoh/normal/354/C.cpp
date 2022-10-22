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

const int MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

int cnt[MAXN], n, ans = 1, k;

inline int Cnt(int L, int R) {
	R = min(R, MAXN - 1);
	if (L > R) return 0;
	return cnt[R] - cnt[L - 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}

	for (int i = 1; i < MAXN; i++) cnt[i] += cnt[i - 1];

	for (int i = 1; i < MAXN; i++) {
		if (cnt[i - 1]) continue;
		bool flag = true;
		for (int j = i; j < MAXN; j += i) flag &= (Cnt(j + k + 1, j + i - 1) == 0);
		if (flag) ans = i;
	}

	cout << ans << endl;
	return 0;
}