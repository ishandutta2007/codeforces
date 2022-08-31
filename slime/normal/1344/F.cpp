#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
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
char x[4] = {'W', 'Y', 'B', 'R'};
bitset<3005> r[2005];
int cnt = 0;
int tp[1005][4];
int res[3005];
int gt(int a, int b) {
	// b : 1, 2, 3
	return (a - 1) * 3 + b;
}
int tr(char q) {
	for (int j = 0; j < 4; j++)
		if (q == x[j]) return j;
}
int t[maxn];
int tot = 0;
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			tp[i][j] = j;
	while (k--) {
		char x[10];
		scanf("%s", x);
		cin >> tot;
		for (int i = 0; i < tot; i++)
			scanf("%d", &t[i]);
		if (x[0] == 'm') {
			char s[10];
			scanf("%s", s);
			int fn = tr(s[0]);
			for (int x = 1; x <= 2; x++) {
				cnt++;
				for (int j = 0; j < tot; j++) {
					int id = t[j];
					r[cnt][gt(id, tp[id][3])] = 1;
					r[cnt][gt(id, tp[id][x])] = 1;
				}
				if (fn & x) r[cnt][0] = 1;
				else r[cnt][0] = 0;
			}
		}
		else {
			int u = tr(x[0]), v = tr(x[1]);
			for (int j = 0; j < tot; j++) {
				int id = t[j];
				swap(tp[id][u], tp[id][v]);
			}
		}
	}
//	cout << cnt << endl;
	int pl = 1;
	int tot = 3 * n;
	for (int i = 1; i <= tot; i++) {
		int ed = 0;
		for (int j = pl; j <= cnt; j++) {
			if (r[j][i]) {
				ed = j;
				break;
			}
		}
		if (!ed) continue;
		swap(r[pl], r[ed]);
		for (int j = 1; j <= cnt; j++) {
			if (j == pl) continue;
			if (r[j][i]) r[j] ^= r[pl];
		}
		pl++;
	} 
	for (int s = pl; s <= cnt; s++) 
		if (r[s][0]) {
			cout << "NO" << endl;
			return 0;
		}
	for (int j = pl - 1; j >= 1; j--) {
		int fn = 0;
		int fe = tot + 1;
		for (int l = 1; l <= tot; l++)
			if (r[j][l]) {
				fn ^= res[l];
				fe = min(fe, l);
			}
		fn ^= r[j][0];
		res[fe] = fn;
	}
	cout << "YES" << endl;
	for (int j = 1; j <= n; j++) {
		int e[4];
		int sum = 0;
		for (int k = 1; k <= 3; k++)
			e[k] = res[gt(j, k)], 
			sum += e[k];
		if (sum >= 2)
			for (int k = 1; k <= 3; k++) e[k] ^= 1;
		e[0] = 1 - e[1] - e[2] - e[3];
		if (e[0]) printf(".");
		else {
			for (int k = 1; k <= 3; k++)
				if (e[k]) printf("%c", x[k]);
		}
	}
	printf("\n");
	return 0;
}