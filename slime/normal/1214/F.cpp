#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define vt vector<int>
#define maxn 400005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int sm[maxn];
struct th {
	int tp, pl, id;
	bool operator < (const th &r) const {
		return pl < r.pl;
	}
}p[maxn]; 
const int pls = 200002;
int nr[maxn], fr[maxn], nx[maxn];
int fl[maxn];
int ns[maxn], res[maxn];
int m, n;
int cal(int a, int b) {
	if (a > b) swap(a, b);
	int dis = b - a;
	return min(dis, m - dis);
}
void mch(int u, int v) {
	if (u > v) swap(u, v);
	res[u] = v - n;
}
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i].pl), p[i].tp = 1, p[i].id = i;
	for (int j = 1; j <= n; j++)
		scanf("%d", &p[j + n].pl), 
		p[j + n].tp = -1, 
		p[j + n].id = j + n;
	sort(p + 1, p + 2 * n + 1);
	int l = 2 * n;
	for (int i = 1; i <= l; i++) {
		sm[i] = sm[i - 1] + p[i].tp;
		if (!fr[sm[i] + pls])
			fr[sm[i] + pls] = i;
	}
	for (int i = l; i >= 1; i--) {
		nr[sm[i] + pls] = i;
		if (nr[sm[i - 1] + pls]) nx[i] = nr[sm[i - 1] + pls];
		else {
			int fsum = -(sm[l] - sm[i - 1]);
			nx[i] = fr[fsum + pls];
		}	
	}
//	while(1);
	ll ans = 0;
	for (int i = 1; i <= l; i++) {
		if (fl[i]) continue;
		int ncnt = 0;
		ns[ncnt++] = i;
		int pl = nx[i];
		while (pl != i) {
			ns[ncnt++] = pl, 
			pl = nx[pl];
		}
		for (int j = 0; j < ncnt; j++)
			fl[ns[j]] = 1;
		ll nans = 1ll * m * maxn;
		for (int t = 0; t < 2; t++) {
			ll n1 = 0;
			for (int i = t; i < ncnt; i += 2) {
				int u = p[ns[i]].pl, v = p[ns[i + 1]].pl;
				if (i == ncnt - 1) v = p[ns[0]].pl;
				n1 += cal(u, v);
			}
			if (n1 < nans) {
				nans = min(nans, n1);
				for (int i = t; i < ncnt; i += 2) {
					int u = p[ns[i]].id, v = p[ns[i + 1]].id;
					if (i == ncnt - 1) v = p[ns[0]].id;
					mch(u, v);
				}
			}
		}
		ans += nans;
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		printf("%d ", res[i]);
	return 0;
}