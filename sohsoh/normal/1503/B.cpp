#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, A[MAXN][MAXN];

bool i_color(int md, int c) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[i][j] == 0 && (i + j) % 2 == md) {
				cout << c << sep << i << sep << j << endl;
				A[i][j] = 1;
				return true;
			}
		}
	}

	return false;
}

int main() {
	cin >> n;

	int t = n * n;
	while (t--) {
		int a;
		cin >> a;
		if (a == 1) {	
			if (!i_color(0, 2)) {
				i_color(1, 3);
			} 
		} else if (a == 2) {
			if (!i_color(1, 1)) {
				i_color(0, 3);
			}
		} else if (a == 3) {
			if (!i_color(1, 1)) {
				i_color(0, 2);
			}
		}
	}
	return 0;
}