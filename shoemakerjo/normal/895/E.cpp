#include <bits/stdc++.h>

using namespace std;

#define maxn 100010

int n, q;
double nums[maxn];
bool haslazy[maxn*4];
double lmlut[maxn*4];
double lval[maxn*4];
double seg[maxn*4];

void delaze(int ss, int se, int si) {
	if (!haslazy[si]) return;
	// if (ss == se) return;
	seg[si] = seg[si]*lmlut[si] + lval[si]*(se-ss+1.0);
	if (ss == se) {
		haslazy[si] = false;
		return;
	}
	if (!haslazy[si*2+1]) {
		haslazy[si*2+1] = true;
		lmlut[si*2+1] = lmlut[si];
		lval[si*2+1] = lval[si];
	}
	else {
		lmlut[si*2+1] = lmlut[si*2+1]*lmlut[si];
		lval[si*2+1] = lval[si*2+1]*lmlut[si] + lval[si];
	}
	if (!haslazy[si*2+2]) {
		haslazy[si*2+2] = true;
		lmlut[si*2+2] = lmlut[si];
		lval[si*2+2] = lval[si];
	}
	else {
		lmlut[si*2+2] = lmlut[si*2+2]*lmlut[si];
		lval[si*2+2] = lval[si*2+2]*lmlut[si] + lval[si];
	}
	haslazy[si] = false;
}

double qu(int qs, int qe, int ss, int se, int si) {
	// cout << "cur  " << seg[si] << endl;
	if (haslazy[si]) delaze(ss, se, si);
	// cout << "     " << seg[si] << endl;
	if (qs > qe || ss > se || qs > se || qe < ss) return 0.0;
	if (qs <= ss && se <= qe) {
		return seg[si];
	}
	int mid = (ss+se)/2;
	return qu(qs, qe, ss, mid, si*2+1) + 
		qu(qs, qe, mid+1, se, si*2+2);
}

double query(int low, int high) {
	return (qu(low, high, 0, n-1, 0)+0.0)/(high-low+1.0);
}

void buildtree(int ss, int se, int si) {
	haslazy[si] = false;
	if (ss == se) {
		seg[si] = nums[ss];
		return;
	}
	int mid = (ss+se)/2;
	buildtree(ss, mid, si*2+1);
	buildtree(mid+1, se, si*2+2);
	seg[si] = seg[si*2+1] + seg[si*2+2];
}

void up(int us, int ue, int ss, int se, int si, double mu, double va) {
	// cout << "       --->   " << mu << "  " << va << endl;
	if (haslazy[si]) delaze(ss, se, si);
	if (us > ue || ss > se || ue < ss || us > se) return;
	if (us <= ss && se <= ue) {
		lmlut[si] = mu;
		lval[si] = va;
		haslazy[si] = true;
		delaze(ss, se, si);
		return;
	}
	int mid = (ss+se)/2;
	up(us, ue, ss, mid, si*2+1, mu, va);
	up(us, ue, mid+1, se, si*2+2, mu, va);
	seg[si] = seg[si*2+1] + seg[si*2+2];
}

void update(int low, int high, double mu, double va) {
	up(low, high, 0, n-1, 0, mu, va);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(15);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	// for (int i = 0; i < maxn*4; i++) haslazy[i] = false;
	buildtree(0, n-1, 0);
	// cout << "initial sum   " << seg[0] << endl;
	int type, l1, r1, l2, r2;
	for (int i = 0; i < q; i++) {
		// cout << "current sum   " << i << "  " << seg[0] << endl;
		cin >> type;
		if (type == 1) {
			cin >> l1 >> r1 >> l2 >> r2;
			l1--; r1--; l2--; r2--;
			double avg1 = query(l1, r1);
			double avg2 = query(l2, r2);
			// cout << "averages  " << avg1 << "   " << avg2 << endl;
			update(l2, r2, (r2-l2-0.0)/(r2-l2+1.0), avg1*(1.0/(r2-l2+1.0)));
			update(l1, r1, (r1-l1-0.0)/(r1-l1+1.0), avg2*(1.0/(r1-l1+1.0)));
		}
		else {
			cin >> l1 >> r1;
			l1--; r1--;
			// cout << "l value " << query(l1, l1) << "   -   " << query(r1, r1) <<  endl;
			cout << query(l1, r1)*(r1-l1+1.0) << endl;
		}
	}
	cin >> n;
}