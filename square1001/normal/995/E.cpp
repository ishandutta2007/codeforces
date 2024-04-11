#include <queue>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int binpow(int a, int b, int p) {
	int ans = 1;
	while (b > 0) {
		if (b & 1) ans = (long long)(ans) * a % p;
		a = (long long)(a) * a % p;
		b >>= 1;
	}
	return ans;
}
int main() {
	int S, T, P;
	cin >> S >> T >> P;
	unordered_map<int, int> dl, dr;
	unordered_map<int, int> pl, pr;
	queue<int> quel, quer;
	quel.push(S); dl[S] = 0;
	int limit = min(P, 300000);
	while (dl.size() < limit) {
		int u = quel.front(); quel.pop();
		int curd = dl[u];
		int na = (u == P - 1 ? 0 : u + 1), nb = (u == 0 ? P - 1 : u - 1), nc = binpow(u, P - 2, P);
		if (dl.find(na) == dl.end()) dl[na] = curd + 1, pl[na] = u, quel.push(na);
		if (dl.find(nb) == dl.end()) dl[nb] = curd + 1, pl[nb] = u, quel.push(nb);
		if (dl.find(nc) == dl.end()) dl[nc] = curd + 1, pl[nc] = u, quel.push(nc);
	}
	quer.push(T); dr[T] = 0;
	while (dr.size() < limit) {
		int u = quer.front(); quer.pop();
		int curd = dr[u];
		int na = (u == P - 1 ? 0 : u + 1), nb = (u == 0 ? P - 1 : u - 1), nc = binpow(u, P - 2, P);
		if (dr.find(na) == dr.end()) dr[na] = curd + 1, pr[na] = u, quer.push(na);
		if (dr.find(nb) == dr.end()) dr[nb] = curd + 1, pr[nb] = u, quer.push(nb);
		if (dr.find(nc) == dr.end()) dr[nc] = curd + 1, pr[nc] = u, quer.push(nc);
	}
	vector<int> path;
	bool shortcut = (dl.find(T) != dl.end());
	bool found = false;
	for (pair<int, int> i : dl) {
		if (dr.find(i.first) == dr.end()) continue;
		if (shortcut && i.first != T) continue;
		vector<int> vl = { i.first }, vr = { i.first };
		int cl = i.first, cr = i.first;
		while (cl != S) cl = pl[cl], vl.push_back(cl);
		while (cr != T) cr = pr[cr], vr.push_back(cr);
		reverse(vl.begin(), vl.end());
		vl.pop_back();
		vl.insert(vl.end(), vr.begin(), vr.end());
		vector<int> curpath;
		for (int i = 1; i < vl.size(); ++i) {
			int a = vl[i - 1], b = vl[i];
			if ((a + 1) % P == b) curpath.push_back(1);
			else if ((a + P - 1) % P == b) curpath.push_back(2);
			else curpath.push_back(3);
		}
		if (!found || (path.size() > curpath.size())) {
			path = curpath;
			found = true;
		}
	}
	assert(found);
	cout << path.size() << endl;
	for (int i = 0; i < path.size(); ++i) {
		if (i) cout << ' ';
		cout << path[i];
	}
	cout << endl;
	return 0;
}