// \_()_/
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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, k;
string s;

bool Ask(int i, int j) {
	int t = 2 * n;
	while (t--) {
		if (s[i] < s[j]) return true;
		if (s[i] > s[j]) return false;
		i = (i + 1) % n;
		j = (j + 1) % n;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> s;
	
	int ind = 0;
	for (int i = 0; i < k; i++) {
		if (Ask(ind, 0)) {
			cout << s[ind];
			ind = (ind + 1) % n;
		} else {
			cout << s[0];
			ind = 1 % n;
		}
	}
	return 0;
}