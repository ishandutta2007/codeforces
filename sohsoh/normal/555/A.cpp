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
	int n, k;
	cin >> n >> k;
	int ans = 2 * n - k + 1;
	for (int i = 1; i <= k; i++) {
		bool flag = true;
		int l;
		cin >> l;

		for (int j = 0; j < l; j++) {
			cin >> A[j];
			if (j == 0 && A[j] != 1) flag = false;
			if (j && A[j] != A[j - 1] + 1) flag = false;
			ans -= 2 * int(flag);
		}
	}

	cout << ans << endl;
	return 0;
}