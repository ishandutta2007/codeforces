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

int A[MAXN], n, x;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		for (int i = 1; i <= 2 * n; i++) cin >> A[i];
		sort(A + 1, A + 2 * n + 1);

		bool flag = true;
		for (int i = 1; i <= n; i++)
			flag &= (A[i] + x <= A[i + n]);
		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}