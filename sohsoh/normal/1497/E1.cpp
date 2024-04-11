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

const ll MAXN = 1e7 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int SPF[MAXN];

inline int val(int x) {
	int lst = 0, ans = 1;
	while (x > 1) {
		int s = SPF[x];
		x /= s;
		if (s == lst) ans /= s, lst = 0;
		else ans *= s, lst = s;
	}

	return ans;
} 

inline int solve() {
	int n, k;
	cin >> n >> k;
	int ans = 1;

	set<int> st;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x = val(x);
		
		if (st.find(x) != st.end()) {
			ans++;
			st.clear();
		}


		st.insert(x);
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 1; i < MAXN; i++) SPF[i] = i;
	for (int i = 2; i < MAXN; i++)
		if (SPF[i] == i)
			for (int j = 2 * i; j < MAXN; j += i)
				if (SPF[j] == j)
					SPF[j] = i;

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}