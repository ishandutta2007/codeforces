#include <bits/stdc++.h>
using namespace std;
#define maxn 1010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
char inp[maxn][maxn];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%s", inp[i] + 1);
	int t[2] = {0, 0};
	for (int i = 1; i <= n; i++) {
		int fl = 0;
		for (int j = 1; j <= m; j++) {
			if ((fl % 2 == 0) && inp[i][j] == '#') fl++;
			if ((fl % 2 == 1) && inp[i][j] == '.') fl++;
		}
		if (fl >= 3) {
			cout << -1 << endl;
			return 0;
		}
		if (!fl) t[0]++;
	}
	for (int i = 1; i <= m; i++) {
		int fl = 0;
		for (int j = 1; j <= n; j++) {
			if ((fl % 2 == 0) && inp[j][i] == '#') fl++;
			if ((fl % 2 == 1) && inp[j][i] == '.') fl++;
		}
		if (fl >= 3) {
			cout << -1 << endl;
			return 0;
		}
		if (!fl) t[1]++;
	}
//	cout << t[0] << ' ' << t[1] << endl;
	if (min(t[0], t[1]) == 0 && max(t[0], t[1]) > 0) {
		cout << -1 << endl;
		return 0;
	}
	int nl = maxn + 1, nr = -maxn;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = maxn + 1, r = -maxn;
		for (int j = 1; j <= m; j++) 
			if (inp[i][j] == '#') l = min(l, j), r = max(r, j);
		if (l <= r) {
			if (nl > nr) ans++;
			else 
				if (l > nr || r < nl) ans++;
		}
		nl = l, nr = r;
	}
	cout << ans << endl;
	return 0;
}