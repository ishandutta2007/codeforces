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

const ll MAXN = 1e7 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll SPF[MAXN], ans[MAXN], D[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 1; i < MAXN; i++) SPF[i] = i;
	for (int i = 2; i < MAXN; i++) 
		if (SPF[i] == i)
			for (int j = i * 2; j < MAXN; j += i)
				if (SPF[j] == j)
					SPF[j] = i;

	D[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		ll s = SPF[i];
		ll cnt = 0;
		ll n = i;
		while (n % s == 0) n /= s, cnt++;
		D[i] += D[n];
		for (int j = 1; j <= cnt; j++) D[i] += s * D[n], s = s * SPF[i];
	} 

	for (int i = 1; i < MAXN; i++) {
		if (D[i] < MAXN && ans[D[i]] == 0)
			ans[D[i]] = i;
	}

	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		if (ans[x] == 0) cout << -1 << endl;
		else cout << ans[x] << endl;
	}
	return 0;
}