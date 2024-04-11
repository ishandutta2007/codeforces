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

#define P 998244353

#define N 300100
int n;
vector<int> A[N];
int f[N][3];

void ff(int x, int y) {
	f[x][0] = 1;
	for (auto i : A[x]) if (i != y) {
		ff(i, x);
		int f0 = 0, f1 = 0, f2 = 0;
		// cut
		f0 = (ll)f[x][0] * (f[i][0] + f[i][1])%P;
		f1 = (ll)f[x][1] * (f[i][0] + f[i][1])%P;
		f2 = (ll)f[x][2] * (f[i][0] + f[i][1])%P;
		// no cut
		f1 = ((ll)f1 + (ll)f[x][0] * (f[i][0] + f[i][2])%P + (ll)f[x][1] * f[i][1]%P + (ll)f[x][2] * (f[i][0] + f[i][2])%P)%P;
		f2 = ((ll)f2 + (ll)f[x][2] * f[i][1]%P + (ll)f[x][0] * f[i][1]%P)%P;

		f[x][0] = f0;
		f[x][1] = f1;
		f[x][2] = f2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		A[x].pb(y);
		A[y].pb(x);
	}
	ff(0, -1);
	int S = (f[0][0] + f[0][1])%P;
	cout << S << endl;
	return 0;
}