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

ll F[MAXN], n, K[MAXN], H[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> K[i];
		for (int i = 1; i <= n; i++)
			cin >> H[i];

		for (int i = 1; i <= n; i++) {
			ll c = H[i];
			int j = i - 1;
			while (c - (K[i] - K[j]) > 0) {
				int x = c - (K[i] - K[j]);
				if (x < H[j]) c += H[j] - x;
				j--;
			}

			F[i] = c * (c + 1) / 2 + F[j];
		}

		cout << F[n] << endl;
	}
	return 0;
}