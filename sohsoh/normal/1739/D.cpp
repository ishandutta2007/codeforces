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

int n, k, P[MAXN], f[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 2; i <= n; i++) cin >> P[i];

		int l = 1, r = n;

		while (l < r) {
			int mid = (l + r) >> 1;
		
			int cnt = 0;
			for (int i = n; i > 1; i--) {
				if (f[i] + 1 > mid - (P[i] != 1)) cnt++, f[i] = -1;
				f[P[i]] = max(f[P[i]], f[i] + 1);	
			}	

			if (cnt <= k) r = mid;
			else l = mid + 1;
		

			for (int i = 0; i < n + 10; i++) f[i] = 0;
		}

		cout << l << endl;
	}
	return 0;
}