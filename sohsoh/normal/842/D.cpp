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

const ll MAXN = 12e6 + 10;
const ll LOG = 19;

int lz[MAXN], C[MAXN][2], n, m, sz = 1;
bool B[MAXN];

inline void Push(int v, int h) {
	if (lz[v] & (1 << h)) swap(C[v][0], C[v][1]);
	lz[C[v][0]] ^= lz[v];
	lz[C[v][1]] ^= lz[v];
	lz[v] = 0;
}

inline void Insert(int x) {
	int v = 1;
	for (int i = LOG - 1; i >= 0; i--) {
		int t = (x >> i) & 1;
		if (!C[v][t]) C[v][t] = ++sz;
		v = C[v][t];
	}	
}

inline int Mex() {
	int v = 1, ans = 0;
	for (int i = LOG - 1; i >= 0; i--) {
		Push(v, i);
		if (C[v][0]) v = C[v][0];
		else v = C[v][1], ans ^= (1 << i);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		B[x] = true;
	}

	for (int i = 0; i < (1 << LOG); i++)
		if (!B[i])
			Insert(i);
	while (m--) {
		int x;
		cin >> x;
		lz[1] ^= x;
		cout << Mex() << endl;
	}
	return 0;
}