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

const ll MAXN = 6e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

vector<pair<int, int>> T[MAXN]; 
int n, A[MAXN];
vector<int> V[MAXN];

inline void Print(int a, int b, int c, int d) {
	cout << "YES" << endl << a << sep << b << sep << c << sep << d << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		V[A[i]].push_back(i);
		if (V[A[i]].size() > 3) 
			Print(V[A[i]][0], V[A[i]][1], V[A[i]][2], V[A[i]][3]);	
	
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ll s = A[i] + A[j];
			for (auto e : T[s]) {
				if (e.X == i || e.Y == i || e.X == j || e.Y == j) continue;
				Print(i, j, e.X, e.Y);
			}

			T[s].push_back({i, j});
		}
	}

	cout << "NO" << endl;
	return 0;
}