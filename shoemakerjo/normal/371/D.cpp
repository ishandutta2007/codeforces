#include <bits/stdc++.h>

using namespace std;
#define maxn 200010
#define INF 1000000000

int n, N;
int seg[maxn*4];
int cap[maxn];
int cur[maxn];

void buildtree(int ss, int se, int si) {
	if (ss == se) {
		seg[si] = ss;
		return;
	}
	int mid = (ss+se)/2;
	buildtree(ss, mid, si*2+1);
	buildtree(mid+1, se, si*2+2);
	seg[si] = min(seg[si*2+1], seg[si*2+2]);
}

int qu(int qs, int qe, int ss, int se, int si) {
	if (qs > qe || ss > se || qe < ss || qs > se) {
		return INF;
	}
	if (qs <= ss && se <= qe) return seg[si];
	int mid = (ss+se)/2;
	return min(qu(qs, qe, ss, mid, si*2+1),
		qu(qs, qe, mid+1, se, si*2+2));
}

int query(int low) {
	return qu(low, N, 1, N, 0);
}

void up(int spot, int ss, int se, int si) {
	if (ss == se) {
		seg[si] = INF;
		return;
	}
	int mid = (ss+se)/2;
	if (spot <= mid) {
		up(spot, ss, mid, si*2+1);
	}
	else {
		up(spot, mid+1, se, si*2+2);
	}
	seg[si] = min(seg[si*2+1], seg[si*2+2]);
}

void fill(int spot, int inc) {
	while (spot <= N) {
		if (inc + cur[spot] <= cap[spot]) {
			cur[spot] += inc;
			break;
		}
		inc -= cap[spot]-cur[spot];
		cur[spot] = cap[spot];
		up(spot, 1, N, 0);
		int nx = query(spot+1);
		spot = nx;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	N = n;
	for (int i = 1; i <= n; i++) {
		cin >> cap[i];
		cur[i] = 0;
	}
	buildtree(1, N, 0);
	int m; cin >> m;
	int type, p, x, k;
	for (int i = 0; i < m; i++) {
		cin >> type;
		if (type == 1) {
			cin >> p >> x;
			fill(p, x);
		}
		else {
			cin >> k;
			cout << cur[k] << endl;
		}
	}
	cin >> m;
}