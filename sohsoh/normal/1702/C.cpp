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

map<int, int> F, L;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		F.clear();
		L.clear();

		int n, q;
		cin >> n >> q;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;

			if (F.find(x) == F.end()) F[x] = L[x] = i;
			else L[x] = i;
		}

		while (q--) {
			int a, b;
			cin >> a >> b;
			if (F[a] && L[b] && F[a] < L[b]) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}