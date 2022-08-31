#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
using namespace std;
char s[maxn];
int rk[maxn], sa[maxn], ct[maxn], a[maxn], b[maxn], n;
void bogo_sort()
{
	memset(ct, 0, sizeof(ct));
	for(int i = 1; i <= n; i++)
		ct[b[i]]++;
	for(int i = 1; i < maxn; i++)
		ct[i] += ct[i - 1];
	for(int i = 1; i <= n; i++)
		rk[i] = ct[b[i]]--, sa[rk[i]] = i;
	memset(ct, 0, sizeof(ct));
	for(int i = 1; i <= n; i++)
		ct[a[i]]++;
	for(int i = 1; i < maxn; i++)
		ct[i] += ct[i - 1];
	for(int i = n; i >= 1; i--)
		rk[sa[i]] = ct[a[sa[i]]]--;
	for(int i = 1; i <= n; i++)
		sa[rk[i]] = i;
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i == 1 || a[sa[i]] != a[sa[i - 1]] || b[sa[i]] != b[sa[i - 1]]) cnt++;
		rk[sa[i]] = cnt;
	}
}
int h[maxn], height[maxn];
int mn[20][maxn], lb[maxn];
void builds() {
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++)
		a[i] = s[i] - 'a', b[i] = 1;
	bogo_sort();
	int l = 1;
	while(l < n)
	{
		for(int i = 1; i <= n; i++)
			a[i] = rk[i], b[i] = rk[i + l];
		bogo_sort();
		l <<= 1;
	}
	for(int i = 1; i <= n; i++)
	{
		h[i] = max(0, h[i - 1] - 1);
		while(i + h[i] <= n && s[i + h[i]] == s[sa[rk[i] + 1] + h[i]]) h[i]++;
	}
	for(int i = 1; i <= n; i++) height[i] = h[sa[i]];
	for (int i = 0; i < 20; i++) {
		for (int j = (1 << i); j < min(maxn, (1 << (i + 1))); j++)
			lb[j] = i;
		for (int j = 1; j <= n; j++)
			if (i == 0) mn[i][j] = height[j];
			else {
				mn[i][j] = mn[i - 1][j];
				if (j + (1 << (i - 1)) <= n)
					mn[i][j] = min(mn[i][j], mn[i - 1][j + (1 << (i - 1))]);
			}
	}
}
int query(int x, int y) {
	// x, y 
	if (x > y) swap(x, y);
	y--;
	int nl = lb[y - x + 1];
	return min(mn[nl][x], mn[nl][y - (1 << nl) + 1]);
}
int st[maxn];
int l[maxn], r[maxn], k[maxn];
int cnt = 0;
char t[maxn];
vector<pi> qq[maxn];
int ans[maxn];
struct bit {
	int d[maxn];
	int lb(int x) {
		return x & -x;
	}
	void ch(int a, int num) {
		while (a < maxn)	
			d[a] += num, 
			a += lb(a);
	}
	int q(int a) {
		int ans = 0;
		while (a) {
			ans += d[a], 
			a -= lb(a); 
		}
		return ans;
	}
	int q(int l, int r) {
		return q(r) - q(l - 1);
	}
}bb;
int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		st[i] = cnt + 1;
		scanf("%s", t);
		int l = strlen(t);
		for (int j = 0; j < l; j++)
			s[++cnt] = t[j];
		s[++cnt] = 'a' + 27;
	}	
	st[n + 1] = cnt + 1;
	builds();
	/*
	for (int i = 1; i <= cnt; i++)
		cout << s[i] << ' ' << rk[i] << ' ' << sa[i] << ' ' << h[i] << endl; 
	*/for (int i = 1; i <= q; i++) {
		scanf("%d%d%d", &l[i], &r[i], &k[i]);
		l[i] = st[l[i]], r[i] = st[r[i] + 1] - 1;
		int nl = st[k[i] + 1] - st[k[i]] - 1;
		// to ki >= nl
		int bg = rk[st[k[i]]], nx = bg;
		for (int j = 19; j >= 0; j--)
			if (bg - (1 << j) > 0 && query(bg - (1 << j), nx) >= nl) bg -= (1 << j);
		qq[bg - 1].pb(mp(i, -1));
		bg = nx;
		for (int j = 19; j >= 0; j--)
			if (bg + (1 << j) <= cnt && query(bg + (1 << j), nx) >= nl) bg += (1 << j);
		qq[bg].pb(mp(i, 1));
	}
	for (int i = 1; i <= cnt; i++) {
		int pl = sa[i];
		bb.ch(pl, 1);
		for (auto v : qq[i]) {
			int nid = v.fi;
			ans[nid] += bb.q(l[nid], r[nid]) * v.se;
		}
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}
/*
2 1
a
ab
1 2 1

*/