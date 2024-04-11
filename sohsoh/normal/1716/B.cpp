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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << n << endl;

		for (int i = n; i > 0; i--) {
			for (int j = 1; j < i; j++) cout << j << sep;
			cout << n << sep;
			for (int j = i; j < n; j++) cout << j << sep;
			cout << endl;
		}
	}
	return 0;
}