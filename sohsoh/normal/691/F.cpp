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

const ll MAXN = 3e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll Ans[MAXN], ps[MAXN], cnt[MAXN], n, tans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		cnt[x]++;
	}

	sort(all(v));
	for (int e : v) {
		int k = (MAXN + e - 1) / e;
		tans += n - (lower_bound(all(v), k) - v.begin());
		if (e * e >= MAXN) tans--;
	}

	for (int i = 1; i < MAXN; i++) {
		for (int j = i; j < MAXN; j += i) {
			ll x = j / i;
			if (x != i) Ans[j] += cnt[i] * cnt[x];
			else Ans[j] += cnt[i] * (cnt[i] - 1);
		}
	}

	
	for (int i = MAXN - 2; i > 0; i--) Ans[i] += Ans[i + 1];

	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		cout << tans + Ans[t] << endl;
	}
	return 0;
}