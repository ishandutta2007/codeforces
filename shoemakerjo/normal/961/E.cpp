#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define maxn 200010
#define ll long long

int seg[maxn*4];
int a[maxn];
vector<int> rem[maxn];

int n;

void update(int spot, int diff, int ss, int se, int si) {
	if (spot > se || spot < ss || ss > se) return;
	if (ss == se) {
		seg[si]+=diff;
		return;
	}
	int mid = (ss+se)/2;
	update(spot, diff, ss, mid, si*2+1);
	update(spot, diff, mid+1, se, si*2+2);
	seg[si] = seg[si*2+1] + seg[si*2+2];
}

int query(int qs, int qe, int ss, int se, int si) {
	if (qs > qe || ss > se || qs > se || qe < ss) return 0;

	if (qs <= ss && se <= qe) return seg[si];

	int mid = (ss+se)/2;
	return query(qs, qe, ss, mid, si*2+1) + query(qs, qe, mid+1, se, si*2+2);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// cout << "here  " << endl;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	fill(seg, seg+maxn*4, 0);
	ll ans = 0LL;
	for (int i = 1; i <= n; i++) {
		// cout << "made it to " << i << endl;
		int cur = query(0, min(n, a[i]), 0, n, 0);
		ans += cur + 0LL;
		if (a[i] >= i) update(i, 1, 0, n, 0);
		if (a[i] <= n) rem[a[i]].push_back(i);
		for (auto v : rem[i]) {
			update(v, -1, 0, n, 0);
		}
	}
	cout << ans << endl;
	cin >> n;
}