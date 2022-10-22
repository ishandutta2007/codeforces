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

ll n, x, y, ps[MAXN], cnt[MAXN];
bool B[MAXN];

inline ll Sum(int L, int R) {
	R = min(R, MAXN - 1);
	if (L > R) return 0;
	return ps[R] - ps[max(L - 1, 0)];
} 

inline ll Cnt(int L, int R) {
	R = min(R, MAXN - 1);
	if (L > R) return 0;
	return cnt[R] - cnt[max(L - 1, 0)];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> x >> y;
	swap(x, y);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
		ps[x] += x;
	}

	for (int i = 1; i < MAXN; i++) cnt[i] += cnt[i - 1], ps[i] += ps[i - 1];
	
	ll ans = y * n;
       	int t = y / x;
	for (int i = 2; i < MAXN; i++) {
		if (B[i]) continue;
		ll tans = 0;
		int rem = i - t;
		
		for (int j = 1; j < MAXN; j += i) {
			tans += Cnt(j, j + rem - 2) * y;
			tans += (Cnt(max(j + rem - 1, j), j + i - 1) * (j + i - 1) - Sum(max(j + rem - 1, j), j + i - 1)) * x;
		}
	
		ans = min(ans, tans);
		for (int j = i; j < MAXN; j += i) B[j] = true;
	}

	cout << ans << endl;
	return 0;
}