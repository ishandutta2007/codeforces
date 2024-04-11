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

ll s = 0, A[MAXN], n, q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	n = (1 << n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];	
		s += A[i];
	} 

	cout << setprecision(10) << fixed << (long double) s / n << endl;
	while (q--) {
		int ind, x;
		cin >> ind >> x;
		s -= A[ind];
		A[ind] = x;
		s += A[ind];

		cout << (long double) s / n << endl;
	}
	return 0;
}