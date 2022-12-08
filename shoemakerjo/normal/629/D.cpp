#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 100010
int n;

ll seg[maxn*4];
int mval[maxn];
ll pval[maxn];

ll qu(int qs, int qe, int ss, int se, int si) {
	if (qs > qe || ss > se || qs > se || qe < ss) return 0LL;
	if (qs <= ss && se <= qe) return seg[si];
	int mid = (ss+se)/2;
	return max(qu(qs, qe, ss, mid, si*2+1),
		qu(qs, qe, mid+1, se, si*2+2));
}

ll query(int spot) {
	return qu(0, spot-1, 0, n, 0);
}

void up(int spot, ll val, int ss, int se, int si) {
	if (spot > se || spot < ss) return;
	seg[si] = max(seg[si], val);
	if (ss == se) return;
	int mid = (ss+se)/2;;
	up(spot, val, ss, mid, si*2+1);
	up(spot, val, mid+1, se, si*2+2);

}

void update(int spot, ll val) {
	up(spot, val, 0, n, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll r, h;
	set<ll> vols;
	map<ll, int> ind;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> r >> h;
		ll v = r*r*h;
		pval[i] = v;
		vols.insert(v);
	} 
	int ct = -1;
	for (set<ll>::iterator it = vols.begin(); it != vols.end(); ++it) {
		ll cur = *it;
		ct++;
		ind[cur] = ct;
	}
	for (int i = 0; i < n; i++) {
		mval[i] = ind[pval[i]];
	}
	ll ans = 0LL;
	fill(seg, seg+maxn*4, 0LL);
	for (int i = 0; i < n; i++) {
		ll cur = query(mval[i]);
		cur += pval[i];
		ans = max(ans, cur);
		update(mval[i], cur);
	}
	double pa = ans*1.0*3.141592653589793238462643383279502;
	cout << fixed << setprecision(10) << pa << endl;
	cin >> r;
}