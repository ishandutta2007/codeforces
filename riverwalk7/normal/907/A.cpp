#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

///* advent of code
typedef istringstream iss;
#define pb push_back
#define ins insert
#define multiset mset
#define getl(A) getline(cin, A)
//*/

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = 1; i <= 200; i++) {
		for (int j = 1; j < i; j++) {
			for (int k = 1; k < i; k++) {
				if (a <= i && i <= 2*a && b <= j && j <= 2*b && c <= k && k <= 2*c
						&& d <= k && k <= 2*d && j > 2*d) {
					cout << i << nl;
					cout << j << nl;
					cout << k << nl;
					return 0;
				}
			}
		}
	}

	cout << -1 << nl;

	return 0;
}