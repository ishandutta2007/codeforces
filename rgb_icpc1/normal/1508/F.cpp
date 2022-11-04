#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i ++)
using namespace std;
const int MN = 25005;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

int p[MN], a[MN], l1[MN], r1[MN], l2[MN], r2[MN];
int rlt = 0;

inline void la(int x, int y) { r2[x] = y, l1[y] = x, rlt++; }
inline void lb(int x, int y) { r1[x] = y, l2[y] = x, rlt++; }
inline void ca(int x, int y) { rlt -= (r2[x] == y && l1[y] == x); }
inline void cb(int x, int y) { rlt -= (r1[x] == y && l2[y] == x); }

void solve(int x, int y) {
	if (p[x] < p[y]) { if (p[x] > p[l1[y]]) ca(x, r2[x]), ca(l1[y], y), la(x, y); }
	else {if (p[y] > p[r1[x]]) cb(x, r1[x]), cb(l2[y], y), lb(x, y); } 
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		a[i] = i;
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		for (int i = l; i <= r; i++) {
			while (a[i] > l) {
				a[i]--;
				solve(a[i], i);
			}
		}
		cout << rlt << endl;
	}

	return 0;

}