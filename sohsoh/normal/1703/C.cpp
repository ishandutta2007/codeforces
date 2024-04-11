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

int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[i];
		for (int i = 1; i <= n; i++) {
			int k;
			cin >> k;

			int t = 0;
			for (int i = 0; i < k; i++) {
				char c;
				cin >> c;
				t += (c == 'D' ? -1 : 1);
				if (t >= 10) t -= 10;
				if (t < 0) t += 10;
			}

			cout << (A[i] - t + 10) % 10 << sep;
		}

		cout << endl;
	}
	return 0;
}