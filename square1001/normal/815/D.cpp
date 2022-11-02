#include <set>
#include <vector>
#include <iostream>
using namespace std;
struct interval {
	int l, r, x;
	interval() : l(0), r(0), x(0) {};
	interval(int l_, int r_, int x_) : l(l_), r(r_), x(x_) {};
};
bool operator<(const interval& v1, const interval& v2) {
	return v1.x != v2.x ? v1.x > v2.x : (v1.l != v2.l ? v1.l < v2.l : v1.r < v2.r);
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, P, Q, R;
	cin >> N >> P >> Q >> R;
	vector<vector<pair<int, int> > > qs(P);
	for(int i = 0; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		qs[P - 1].push_back(make_pair(b, c));
		qs[a - 1].push_back(make_pair(Q, c));
		qs[a - 1].push_back(make_pair(b, R));
	}
	long long cur = 0, ans = 0;
	set<interval> stairs = { interval(0, Q, 0) };
	for(int i = P - 1; i >= 0; --i) {
		for(pair<int, int> j : qs[i]) {
			int x = j.first, y = j.second;
			set<interval>::iterator it = stairs.lower_bound(interval(-1, -1, y - 1));
			interval ins(-1, -1, -1);
			int pl = x;
			while(it != stairs.end()) {
				int sl = it->l, sr = it->r, sx = it->x;
				if(sl >= x) break;
				pl = min(pl, sl);
				it = stairs.erase(it);
				cur -= 1LL * (sr - sl) * sx;
				if(sr > x) ins = interval(x, sr, sx);
			}
			if(pl < x) stairs.insert(interval(pl, x, y)), cur += 1LL * (x - pl) * y;
			if(ins.x != -1) stairs.insert(ins), cur += 1LL * (ins.r - ins.l) * ins.x;
		}
		ans += cur;
	}
	cout << 1LL * P * Q * R - ans << endl;
	return 0;
}