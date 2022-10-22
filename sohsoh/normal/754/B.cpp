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

int G[4][4];

inline int f(int x, int y, int z) {
	if (x == y && y == z) return x;
	return 0;
}

inline bool winner() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			if (f(G[i][j], G[i][j + 1], G[i][j + 2])) return true;
			if (f(G[j][i], G[j + 1][i], G[j + 2][i])) return true;
		}
	}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (f(G[i][j], G[i + 1][j + 1], G[i + 2][j + 2]))
				return true;

	for (int i = 0; i < 2; i++)
		for (int j = 2; j < 4; j++)
			if (f(G[i][j], G[i + 1][j - 1], G[i + 2][j - 2]))
				return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			char c;
			cin >> c;
			if (c == '.') G[i][j] = 0;
			else if (c == 'x') G[i][j] = 1;
			else G[i][j] = 2;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (!G[i][j]) {
				G[i][j] = 1;
				if (winner()) return cout << "YES" << endl, 0;
				G[i][j] = 0;
			}
		}
	}

	cout << "NO" << endl;
	return 0;
}