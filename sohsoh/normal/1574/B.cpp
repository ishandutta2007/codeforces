// orz ?
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
		int a, b, c, m, n;
		cin >> a >> b >> c >> m;
		n = a + b + c;
		m = n - 1 - m;
		if (m < 2) cout << "NO" << endl;
		else {
			if (a > b) swap(a, b);
			if (b > c) swap(b, c);
			if (a > b) swap(a, b);
	
			if (c > a + b + 1) c = a + b + 1;	
			if (m <= a + b + c - 1) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	} 
	return 0;
}