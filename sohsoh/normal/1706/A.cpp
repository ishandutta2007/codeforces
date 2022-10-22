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
		int n, m;
		string s;
		cin >> n >> m;
		for (int i = 0; i < m; i++) s += 'B';
		
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			
			x = min(x - 1, m - x);
			if (s[x] == 'B') s[x] = 'A';
			else s[m - x - 1] = 'A';
		}

		cout << s << endl;
	}
	return 0;
}