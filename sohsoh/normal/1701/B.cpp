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

bool vis[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		cout << 2 << endl;
		for (int i = 1; i <= n; i++) {
			if (i & 1) {
				int j = i;
				while (j <= n) {
					cout << j << sep;
					j *= 2;
				}
			}
		}

		cout << endl;
	}
	return 0;
}