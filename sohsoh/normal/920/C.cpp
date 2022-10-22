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

int n, A[MAXN];
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	cin >> s;

	int f = 1;
	for (int i = 2; i <= n; i++) {
		if (s[i - 2] == '0') {
			sort(A + f, A + i);
			f = i;
		} else if (i == n)
			sort(A + f, A + n + 1);
	}

	if (is_sorted(A + 1, A + n + 1)) return cout << "YES" << endl, 0;
	cout << "NO" << endl;
	return 0;
}