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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int m, n, ind1[MAXN], ind2[MAXN];
string s, t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b, k;
	cin >> a >> b >> k;
	if (a == 0) {
		if (k) cout << "NO" << endl;
		else  {
			cout << "YES" << endl;
			for (int i = 1; i <= b; i++) cout << 1;
			cout << endl;	
			for (int i = 1; i <= b; i++) cout << 1;
			cout << endl;
		}

		return 0;
	}


	if (b > 1) {
		if (k <= a + b - 2) {
			cout << "YES" << endl;
			string s;
			for (int i = 1; i <= b; i++) s.push_back('1');
			for (int i = 1; i <= a; i++) s.push_back('0');
			cout << s << endl;
			if (k == 0) {
				cout << s << endl;
				return 0;
			}

			for (int i = 1; i < b; i++) {
				if (i + k < a + b && s[i + k] != s[i]) {
					swap(s[i + k], s[i]);
					cout << s << endl;
					return 0;
				}
			}
		} else cout << "NO" << endl;
	} else {
		if (k == 0) {
			cout << "YES" << endl;
			cout << 1;
			for (int i = 1; i <= a; i++) cout << 0;
			cout << endl;
			cout << 1;
			for (int i = 1; i <= a; i++) cout << 0;
			cout << endl;
		} else cout << "NO" << endl;
	}
	return 0;
}