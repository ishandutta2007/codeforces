// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;
//#define double long double
const int N = (int) 2e5 + 6, mod = (int) 0;
const double pi = acos(-1);
int n, m, nxt[N], px[N], par[N], steps[N], py[N], o[N];
double xl[N], xr[N], ang_sv[N];
double angle(int x) {
	double res = atan2(py[x], px[x]);	
	res += pi;
	return res;
}
int cmp(int x, int y) {
	return angle(x) < angle(y);	
}
int mark[N];
pair<int, int> find(int v) {
	if (v == par[v]) return mp(v, 0);
	auto x = find(par[v]);
	x.second += steps[v];
	steps[v] = x.second;
	par[v] = x.first;
	return x;
}
int check(double rr) {
	{
//	vector<pair<pair<double, double>, int>> all;
	for (int i = 0; i < n; ++i) {
		int j = o[i];
		double d = sqrt((LL) px[j] * px[j] + (LL) py[j] * py[j]);
		double range = acos(rr / d);
		double ang = ang_sv[j];//angle(j);
		xl[j] = ang - range;
		xr[j] = ang + range;
//		all.pb(mp(mp(xl[j], xr[j]), j));
//		all.pb(mp(mp(xl[j] + 2 * pi, (xr[j] + 2 * pi)), j));
	}
	/*
	sort(ALL(all));
	set<pair<double, int>, greater<pair<double, int>>> st;
	memset(mark, 0, sizeof mark);
	for (auto s : all) {
		double l = s.x.x, r = s.x.y;
		int id = s.y;
		while ((int) st.size()) {
			auto p = *(st.begin());
			if (p.x >= r) {
				mark[p.y] = 1;
				st.erase(st.begin());
				continue;
			}
			break;
		}
		st.insert(mp(r, id));
	}
	*/
	}
	int cnt = 0;
	{
	vector<pair<pair<double, double>, int>> all;
	for (int j = 0; j < n; ++j) mark[j] = 1;
	for (int turn = 0; turn <= 1; ++turn) {
		for (int i = 0; i < n; ++i) {
			int j = o[i];
			double l = xl[j] + turn * 2 * pi, r = xr[j] + turn * 2 * pi;
			if ((int) all.size() && l < all.back().x.first) {
				mark[j] = 0;
				continue;
			}
			while ((int) all.size() && r < all.back().x.second) mark[all.back().second] = 0, all.pop_back();
			all.pb(mp(mp(xl[j] + turn * 2 * pi, xr[j] + turn * 2 * pi), j));
		}
	}
	}
	vector<pair<double, double>> all;
	for (int turn = 0; turn <= 1; ++turn)
		for (int i = 0; i < n; ++i) if (mark[o[i]]) {
			int j = o[i];
			all.pb(mp(xl[j] + turn * 2 * pi, xr[j] + turn * 2 * pi));
		}
	cnt = (int) all.size() / 2;
//	sort(ALL(all));
	int pt = 0;
	for (int pos = 0; pos < 2 * cnt; ++pos) {
		double r = all[pos].second;
		while (pt < 2 * cnt && all[pt].first <= r) ++pt;
		nxt[pos] = pt;//lower_bound(ALL(all), mp(r, 1e9)) - all.begin();
		par[pos] = pos;
		steps[pos] = 0;
	}
	if ((int) all.size() == 1) return 1;
	for (int st = 0; st < cnt; ++st) {
		auto see = find(st);
		int reach = see.first, step = see.second;
		while (reach < st + cnt) {
			int nx = nxt[reach];
			if (nx >= st + cnt) break;
			if (all[nx].second > 2 * pi + all[st].second) {
				break;
			}
			par[reach] = nx;
			steps[reach] = 1;
			++step;
			auto to_nxt = find(nx);
			step += to_nxt.second;
			reach = to_nxt.first;
		}
		if (step + 1 <= m) {
			return 1;
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	double bl = 0, br = 1e6;
	long long mn = 1e18;
	for (int j = 0; j < n; ++j) {
		cin >> px[j] >> py[j];
		o[j] = j;
		ang_sv[j] = angle(j);
		mn = min(mn, (LL) px[j] * px[j] + (LL) py[j] * py[j]);
		br = min(br, sqrt((LL) px[j] * px[j] + (LL) py[j] * py[j]));
	}
	if (mn == 0) {
		cout << setprecision(20) << fixed << 0. << endl;
		return 0;
	}
	sort(o, o + n, cmp);
	for (int j = 0; j < 100; ++j) {
		double bm = (bl + br) / 2;
		if (check(bm)) {
			bl = bm;
		} else {
			br = bm;
		}
	}
	cout << setprecision(20) << fixed << bl << endl;
	
}