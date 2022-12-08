#include <bits/stdc++.h>

using namespace std;

#define maxn 100010
#define pdd pair<double, double>

double rig[maxn*4];
double lef[maxn*4];
double orig[maxn];

int n, q;
vector<pdd> qv;

void recalc(int si) {
	//recalc my r value first
	double r1 = rig[si*2+1];
	double r2 = rig[si*2+2];
	double l1 = lef[si*2+1];
	double l2 = lef[si*2+2];
	double ri = r2;
	ri += (1-r2)*r1*l2/(1.0-(1.0-l2)*r1);
	rig[si] = ri;
	lef[si] = l1*l2/(1.0-(1.0-l2)*r1);
}

pdd calc(double l1, double r1, double l2, double r2) {
	// cout << "calc with  " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
	double ri = r2;
	ri += (1-r2)*r1*l2/(1.0-(1.0-l2)*r1);
	double le = l1*l2/(1.0-(1.0-l2)*r1);
	return pdd(le, ri);
}

void up(int spot, double val, int ss, int se, int si) {
	if (spot < ss || spot > se) {
		return;
	}
	if (ss == se) {
		lef[si] = rig[si] = val;
		return;
	}
	int mid = (ss+se)/2;
	up(spot, val, ss, mid, si*2+1);
	up(spot, val, mid+1, se, si*2+2);
	recalc(si);
}

void update(int spot, double val) {
	up(spot, val, 1, n, 0);
}

void qu(int qs, int qe, int ss, int se, int si) {
	if (qs > qe || ss > se || qs > se || qe < ss) {
		return;
	}
	if (qs <= ss && se <= qe) {
		qv.push_back(pdd(lef[si], rig[si]));
		return;
	}
	int mid = (ss+se)/2;
	qu(qs, qe, ss, mid, si*2+1);
	qu(qs, qe, mid+1, se, si*2+2);

}

double query(int l, int r) {
	qv.clear();
	qu(l, r, 1, n, 0);
	// for (int i = 0; i < qv.size(); i++) {
	// 	cout << qv[i].first << "  " << qv[i].second << "  -  ";
	// }
	// cout << endl;
	double lcur = qv[0].first;
	double rcur = qv[0].second;
	for (int i = 1; i < qv.size(); i++) {
		pdd tempo = calc(lcur, rcur, qv[i].first, qv[i].second);
		lcur = tempo.first;
		rcur = tempo.second;
	}
	return lcur;
}

void buildtree(int ss, int se, int si) {
	if (ss == se) {
		rig[si] = lef[si] = orig[ss];
		return;
	}
	int mid = (ss+se)/2;
	buildtree(ss, mid, si*2+1);
	buildtree(mid+1, se, si*2+2);
	recalc(si);
}
//
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	cin >> n >> q;
	int a, b;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		orig[i] = (a+0.0)/(b+0.0);
	}
	buildtree(1, n, 0);
	int tp, l, r, ind;
	while (q-- > 0) {
		cin >> tp;
		if (tp == 1) {
			cin >> ind >> a >> b;
			double cur = (a+0.0)/b;
			update(ind, cur);
		}
		if (tp == 2) {
			cin >> l >> r;
			cout << query(l, r) << endl;
		}
	}
	cin >> n;
}