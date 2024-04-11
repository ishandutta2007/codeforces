#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 100010
int n, m;
vector<int> A[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		A[x].pb(y);
		A[y].pb(x);
	}
	for (int i = 0; i < n; i ++) {
		sort(A[i].begin(), A[i].end());
	}
	for (int k = 1; k < n; k ++) if (n%k == 0) {
		bool F = true;
		for(int i = 0; i < n-k && F; i ++) {
			if (A[i].size() != A[i+k].size()) F = false;
			vector<int> B;
			for (auto j : A[i]) B.pb((j+k)%n);
			sort(B.begin(), B.end());
			if (B != A[i+k]) F = false;
		}
		if (F) {
			puts ("Yes");
			return 0;
		}
	}
	puts ("No");
	return 0;
}