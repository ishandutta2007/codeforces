// orz
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s >> s;

		if (s.size() == 1) cout << -1 << sep << -1 << endl;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] != s[i + 1]) {
				cout << i + 1 << sep << i + 2 << endl, 0;
				break;
			}

			if (i == s.size() - 2) cout << -1 << sep << -1 << endl;
		}
	}
	return 0;
}