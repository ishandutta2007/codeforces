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
		string s;
		cin >> s;
		if (s[0] != 'Y' && s[0] != 'y') cout << "NO" << endl;
		else if (s[1] != 'E' && s[1] != 'e') cout << "NO" << endl;
		else if (s[2] != 'S' && s[2] != 's') cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}