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

int A[MAXN], B[MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[i];
		for (int i = 1; i <= n; i++) cin >> B[i];

		int p = 1;
		for (int i = 1; i <= n; i++) {
			while (B[p] < A[i]) p++;
			cout << B[p] - A[i] << sep;
		}

		cout << endl;

		p = n;
		vector<int> ans;
		for (int i = n; i > 0; i--) {
			if (i < n && B[i] < A[i + 1]) p = i;
			ans.push_back(B[p] - A[i]);
		}

		reverse(all(ans));
		for (int e : ans) cout << e << sep;
		cout << endl;
	}
	return 0;
}