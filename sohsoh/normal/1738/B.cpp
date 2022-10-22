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

ll A[MAXN], S[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		ll s = 0;	

		bool flag = true;
		for (int i = 1; i <= k; i++) {
			cin >> S[n - k + i];
			if (i > 1) A[n - k + i] = S[n - k + i] - S[n - k + i - 1], s += A[n - k + i];
			if (i > 2) flag &= (A[n - k + i] >= A[n - k + i - 1]);
			
		}

		if (n == 1) {
			cout << "YES" << endl;
			continue;
		}

		if (k == n) flag &= (S[1] <= A[2]);
		else if (k > 1) {
			s += (n - k + 1) * A[n - k + 2];
			flag &= (s >= S[n]);
		}

		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}