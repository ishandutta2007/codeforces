#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 500010
int seg[maxn*4];
int orig[maxn];

void buildtree(int ss, int se, int si) {
	if (ss == se) {
		seg[si] = orig[ss];
		return;
	}
	int mid = (ss+se)/2;
	buildtree(ss, mid, si*2+1);
	buildtree(mid+1, se, si*2+2);
	seg[si] = __gcd(seg[si*2+1], seg[si*2+2]);
}

void up(int spot, int val, int ss, int se, int si) {
	if (ss > se || spot > se || spot < ss) return;
	if (ss == se) {
		seg[si] = val;
		return;
	}
	int mid = (ss+se)/2;
	if (spot <= mid) up(spot, val, ss, mid, si*2+1);
	else up(spot, val, mid+1, se, si*2+2);
	seg[si] = __gcd(seg[si*2+1], seg[si*2+2]);
}

int query(int qs, int qe, int ss, int se, int si) {
	if (qs > qe || ss > se || qs > se || qe < ss) return 0;
	if (qs <= ss && se <= qe) {
		return seg[si];
	}
	int mid = (ss+se)/2;
	return __gcd(query(qs, qe, ss, mid, si*2+1),
		query(qs, qe, mid+1, se, si*2+2));
}


int cl, cr, cx;

void gd(int ss, int se, int si) {
	if (cr < ss-1) return;
	if (ss > se) return;
	if (seg[si] % cx == 0) {
		cr = max(cr, se);
		return;
	}
	if (ss == se) return;
	int mid = (ss+se)/2;
	if (seg[si*2+1] % cx == 0) {
		cr = max(cr, mid);
		gd(mid+1, se, si*2+2);
	}
	else {
		gd(ss, mid, si*2+1);
	}
}

void qu(int ss, int se, int si) {
	if (ss > se) return;
	if (ss == se) return;
	int mid = (ss+se)/2;
	if (cl > mid) {
		qu(mid+1, se, si*2+2);
	}
	else {
		qu(ss, mid, si*2+1);
		if (cr == mid) {
			gd(mid+1, se, si*2+2);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> orig[i];
	}
	buildtree(1, n, 0);
	int q;
	cin >> q;
	int tp, l, r, spot, y, x;
	for (int i = 0; i < q; i++) {
		cin >> tp;
		if (tp == 1) {
			cin >> l >> r >> x;
			if (query(l, r, 1, n, 0) % x == 0) {
				cout << "YES" << endl;
				continue;
			}
			if (orig[l] % x != 0) {
				if (l == r || query(l+1, r, 1, n, 0) % x == 0) {
					cout << "YES" << endl;

				}
				else cout << "NO" << endl;
				continue;
			}
			// int en = l;
			cl = l;
			cr = l;
			cx = x;
			qu(1, n, 0);
		
			if (cr >= r-1 || query(cr+2, r, 1, n, 0) % x == 0) {
				cout << "YES" << endl;
			}
			else cout << "NO" << endl;
		}
		else {
			cin >> spot >> y;
			up(spot, y, 1, n, 0);
			orig[spot] = y;
		}
	}
	cin >> n;

		// for (int j = 19; j >= 0; j--) { //THIS IS THE SLOW PART
			// 	int off = (1 << j);
			// 	if (en + off > r) continue;
			// 	if (query(en+1, en+off, 1, n, 0) % x == 0) {
			// 		en = en+off;
			// 	}
			// }
}