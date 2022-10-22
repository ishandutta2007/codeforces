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
	while (t--){
		int n, l, r, k;
		cin >> n >> l >> r >> k;
		for (int i = 0; i < n; i++)
			cin >> A[i];
		sort(A, A + n);

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (A[i] >= l && A[i] <= r && A[i] <= k) {
				ans++;
				k -= A[i];
			}
		}

		cout << ans << endl;
	}
	return 0;
}