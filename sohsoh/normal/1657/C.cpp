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

int f[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		f[n] = n;
		for (int i = n - 1; i >= 0; i--)
			f[i] = (s[i] == ')' ? i : f[i + 1]);

		int c = 0, p = 0;
		while (p < n - 1) {
			if (s[p] == '(') p += 2, c++;
			else {
				if (f[p + 1] == n) break;
				p = f[p + 1] + 1;
				c++;
			}
		}

		cout << c << sep << n - p << endl;
	}
	return 0;
}