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
		for (int i = 0; i < 12; i++)
			f[i] = 0;

		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int b, d;
			cin >> b >> d;
			f[d] = max(f[d], b);
		}
		
		int s = 0;
		bool flag = true;
		for (int i = 1; i <= 10; i++) {
			flag &= (f[i] > 0);
			s += f[i];
		}

		cout << (flag ? to_string(s) : "MOREPROBLEMS") << endl;
	}
	return 0;
}