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
const int S = 105;
struct BIT {
	int d[maxn];
	int lb(int x) {
		return x & -x;
	}
	void ch(int pl, int num) {
		if (!pl) return ;
		while (pl < maxn)
			d[pl] += num, 
			pl += lb(pl);
	}
	int q(int pl) {
		int ans = 0;
		while (pl)
			ans += d[pl], 
			pl -= lb(pl);
		return ans;
	}
}r[S];

const int U = maxn * 2;
int cnt[S][U];
int n;
int bl[maxn], bg[maxn], ed[maxn];
int a[U];
int tp[U], l[U], pl[U];
int tcnt;
const int dv = 1005;
void ins(int num, int pl, int tp) {
	for (int i = bl[pl]; i <= tcnt; i++) {
	//	cout << i << endl;
		r[i].ch(cnt[i][num], -1);
		cnt[i][num] += tp;
		r[i].ch(cnt[i][num], 1);
	}
}
int main() {
	cin >> n;
	vi LW;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), 
		LW.pb(a[i]);
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &tp[i], &l[i], &pl[i]), 
		LW.pb(l[i]);
	sort(LW.begin(), LW.end());
	
	tcnt = 0;
	for (int i = 1; i <= n; ) {
		tcnt++;
		int r = min(n, i + dv - 1);
		bg[tcnt] = i, ed[tcnt] = r;
		for (int j = i; j <= r; j++)
			bl[j] = tcnt;
		i = r + 1;
	}

	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(LW.begin(), LW.end(), a[i]) - LW.begin();
	for (int i = 1; i <= n; i++)
		ins(a[i], i, 1);	
//	cout << "AF" << endl;
	for (int i = 1; i <= m; i++) {
		if (tp[i] == 1) {
			l[i] = lower_bound(LW.begin(), LW.end(), l[i]) - LW.begin();
			ins(a[pl[i]], pl[i], -1);
			a[pl[i]] = l[i];
			ins(a[pl[i]], pl[i], 1);
		}
		else {
			if (l[i] == 1) printf("%d\n", LW[a[pl[i]]]);
			else {
				int npl = pl[i], nid = a[npl], nnum;
				int nbl = bl[npl];
				if (nbl == 0) return npl;
				nnum = cnt[nbl - 1][nid];
				for (int i = bg[nbl]; i <= npl; i++)
					if (a[i] == nid) nnum++; 
				if (l[i] % 2 == 0)
					printf("%d\n", nnum);
				else {
					int nans = r[nbl - 1].q(maxn - 1) - r[nbl - 1].q(nnum - 1);
					for (int i = bg[nbl]; i <= npl; i++) {	
						cnt[nbl - 1][a[i]]++;
						if (cnt[nbl - 1][a[i]] == nnum) nans++;
					}
					for (int i = bg[nbl]; i <= npl; i++)
						cnt[nbl - 1][a[i]]--;
					printf("%d\n", nans);
				}
			}
		}
	}
	return 0;
}