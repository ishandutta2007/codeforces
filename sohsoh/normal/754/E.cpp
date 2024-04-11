// Sohsoh84 :)))
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

const ll MAXN = 400 + 10;

int n, m, r, c;
char G[MAXN][MAXN];
bitset<MAXN> R[26][MAXN], F[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> G[i][j];
			R[G[i][j] - 'a'][i].set(j);
			F[i].set(j);
		}
	}

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char c;
			cin >> c;
			if (c == '?') continue;

			for (int x = 0; x < n; x++)
				F[(x - i + 400 * n) % n] &= ((R[c - 'a'][x] >> ((j + 400 * m) % m)) | (R[c - 'a'][x] << ((m - j + 400 * m) % m)));
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << F[i][j];
		cout << endl;
	}
	return 0;
}