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

bool key[4];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		key[0] = key[1] = key[2] = false;

		bool flag = true;
		for (int i = 0; i < 6; i++) {
			if (s[i] == 'r') key[0] = true;
			if (s[i] == 'g') key[1] = true;
			if (s[i] == 'b') key[2] = true;
			if (s[i] == 'R' && !key[0]) flag = false;
			if (s[i] == 'G' && !key[1]) flag = false;
			if (s[i] == 'B' && !key[2]) flag = false;
		}

		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}