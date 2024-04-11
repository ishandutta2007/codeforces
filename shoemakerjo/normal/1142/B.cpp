#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;

int n, m, q;

#define pii pair<int, int>
#define pp pair<pii, int>

#define mp make_pair

int p[maxn];
int nums[maxn];

int st[maxn]; //starting index of longest guy
//then we do a range maximum query

int seg[maxn*4];


int query(int qs, int qe, int ss = 1, int se = m, int si = 0) {
	if (qs > qe || qs > se || qe < ss) return -1;
	if (qs <= ss && se <= qe) return seg[si];

	int mid = (ss+se)/2;
	return max(query(qs, qe, ss, mid, si*2+1),
		query(qs, qe, mid+1, se, si*2+2));
}

void upd(int spot, int val, int ss = 1, int se = m, int si = 0) {
	if (spot < ss || spot > se) return;

	if (ss == se) {
		seg[si] = max(seg[si], val);

	}
	int mid = (ss+se)/2;
	if (spot <= mid) upd(spot, val, ss, mid, si*2+1);
	else upd(spot, val, mid+1, se, si*2+2);

	seg[si] = max(seg[si*2+1], seg[si*2+2]);
}

void buildseg(int ss = 1, int se = m, int si = 0) {
	if (ss == se) {
		seg[si] = st[ss];
		return;
	}
	int mid = (ss + se)/2;
	buildseg(ss, mid, si*2+1);
	buildseg(mid+1, se, si*2+2);

	seg[si] = max(seg[si*2+1], seg[si*2+2]);
}

int numaft[maxn];
int numbef[maxn];
int bef[maxn];

int cind[maxn];
int par[19][maxn];

int walk(int u, int k) {
	for (int j = 18; j>= 0; j--) {
		if (k & (1 << j)) {
			u = par[j][u];
		}
	}
	return u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];

	}
	for (int i = 1; i <= n; i++) {
		numaft[p[i]] = p[i+1];
		if (i == n) numaft[p[i]] = p[1];

		numbef[p[i]] = p[i-1];
		if (i == 1) numbef[p[i]] = p[n];

		// cout << p[i] << " -- " << numbef[p[i]] << endl;

	}
	for (int i = 1; i <= m; i++) {
		cin >> nums[i];
	}

	for (int i = 1; i <= m; i++) {
		bef[i] = cind[numbef[nums[i]]];
		cind[nums[i]] = i;
		par[0][i] = bef[i];

		// cout << i << " -- " << bef[i] << endl;
	}

	for (int i = 1; i < 19; i++) {
		for (int j = 1; j <= m; j++) {
			par[i][j] = par[i-1][par[i-1][j]];
		}
	}

	for (int i = 1; i <= m; i++) {
		st[i]  = walk(i, n-1);
		// cout << i << " :: " << st[i] << endl;
	}

	buildseg();
	int l, r;
	while (q--) {
		cin >> l >> r;
		if (query(l, r) >= l) {
			cout << 1;
		}
		else cout << 0;
	}
	cout << endl;

}