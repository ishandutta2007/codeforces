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
const ll LOG = 30;

int n, A[MAXN], B[MAXN];

inline void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> B[i];

	int mask = 0;
	for (int i = LOG - 1; i >= 0; i--) {
		mask ^= (1 << i);
		
		vector<int> avec, bvec;
		for (int j = 1; j <= n; j++) {
			avec.push_back(mask & A[j]);
			bvec.push_back(mask & (((1 << LOG) - 1) ^ B[j]));
		}

		sort(all(avec));
		sort(all(bvec));

		if (avec != bvec) mask ^= (1 << i);
	}

	cout << mask << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}