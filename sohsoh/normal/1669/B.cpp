#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int cnt[MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < n + 5; i++) cnt[i] = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}

		cout << (*max_element(cnt, cnt + n + 2) >= 3 ? max_element(cnt, cnt + n + 2) - cnt : -1) << endl;
	}
	return 0;
}