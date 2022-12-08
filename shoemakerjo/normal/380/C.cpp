#include <bits/stdc++.h>
#define maxn 1000001
using namespace std;

int seg[maxn*3][3];
int n;

vector<int> ind;

void query(int qs, int qe, int ss, int se, int si) {
	if (qs > se || qe < ss) return;
	if (qs <= ss && se <= qe) {
		ind.push_back(si);
		return;
	}
	int mid = (ss+se)/2;
	query(qs, qe, ss, mid, si*2+1);
	query(qs, qe, mid+1, se, si*2+2);
}

void qu(int qs, int qe) {
	query(qs, qe, 0, n-1, 0);
}

void up(int spot, int val, int ss, int se, int si) {
	if (spot < ss || spot > se) {
		return;
	}
	if (ss == se) {
		seg[si][0] = 0;
		seg[si][1] = val;
		seg[si][2] = 1-val;
		return;
	}
	int mid = (ss+se)/2;
	up(spot, val, ss, mid, si*2+1);
	up(spot, val, mid+1, se, si*2+2);
	int cval = min(seg[si*2+1][1], seg[si*2+2][2]);
	seg[si][0] = seg[si*2+1][0] + seg[si*2+2][0] + cval;
	seg[si][1] = seg[si*2+1][1] + seg[si*2+2][1] - cval;
	seg[si][2] = seg[si*2+1][2] + seg[si*2+2][2] - cval;

}

void update(int spot, int val) {
	up(spot, val, 0, n-1, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < maxn*3; i++) {
		seg[i][0] = seg[i][1] = seg[i][2] = 0;
	}
	string line;
	cin >> line;
	n = line.length();
	for (int i = 0; i < n; i++) {
		if (line[i] == '(') {
			update(i, 1);
		}
		else {
			update(i, 0);
		}
	}
	int m;
	cin >> m;
	int l, r;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		l--; r--;
		ind.clear();
		qu(l, r);
		int cans = 0;
		int copen = 0;
		for (int i = 0; i < ind.size(); i++) {
			int spot = ind[i];
			cans += seg[spot][0];
			int val = min(copen, seg[spot][2]);
			cans += val;
			copen -= val;
			copen += seg[spot][1];
		}
		cout << cans*2 << '\n';
	}
	// cin >> m;


}