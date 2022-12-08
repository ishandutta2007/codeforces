#include <bits/stdc++.h>

using namespace std;
#define maxn 200010

int n, k, a, b, q;
int seg[2][maxn*4]; //0 is for b, 1 is for a
int bv[maxn];
int av[maxn];

void up(int spot, int ss, int se, int si) {
	if (spot < ss || spot > se || ss > se) return;
	if (spot == ss && spot == se) {
		seg[0][si] = bv[spot];
		seg[1][si] = av[spot];
		return;
	}
	int mid = (ss+se)/2;
	if (spot <= mid) {
		up(spot, ss, mid, si*2+1);
	}
	else {
		up(spot, mid+1, se, si*2+2);
	}
	seg[0][si] = seg[0][si*2+1] + seg[0][si*2+2];
	seg[1][si] = seg[1][si*2+1] + seg[1][si*2+2];
}

void update(int spot, int inc) {
	//add inc more order to index spot
	bv[spot]+=inc;
	av[spot]+=inc;
	bv[spot] = min(bv[spot], b);
	av[spot] = min(av[spot], a);
	up(spot, 1, n, 0);
}

int qu(int ind, int qs, int qe, int ss, int se, int si) {
	if (qs > qe || ss > se || qe < ss || qs > se) return 0;
	if (qs <= ss && se <= qe) {
		return seg[ind][si];
	}
	int mid = (ss+se)/2;
	return qu(ind, qs, qe, ss, mid, si*2+1) + 
		qu(ind, qs, qe, mid+1, se, si*2+2);
}

int query(int ind, int qs, int qe) {
	return qu(ind, qs, qe, 1, n, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill(seg[0], seg[0]+maxn*4, 0);
	fill(seg[1], seg[1]+maxn*4, 0);
	fill(bv, bv+maxn, 0);
	fill(av, av+maxn, 0);
	cin >> n >> k >> a >> b >> q;
	int tp;
	int di, ai, pi;
	while (q--) {
		cin >> tp;
		if (tp == 1) {
			cin >> di >> ai;
			update(di, ai);
		}
		else {
			cin >> pi;
			int ans = query(0, 1, pi-1) + query(1, pi+k, n);
			cout << ans << endl;
		}
	}
	cin >> tp;

}