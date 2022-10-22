#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 2002;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
std::mt19937 rd(114514);
int n, m;
struct node {
	int x, y;
} a[maxn];
inline int sqr(int x) { return x * x; }
typedef std::pair<double, double> pr;
const double pi = std::acos(-1), eps = 1e-9;
double dis[maxn][maxn];
inline double upt(double x) {
	if(x < -pi) return x + pi + pi;
	if(x > pi) return x - pi - pi;
	return x;
}
inline pr get(int x, int y, double d) {
	double base = std::atan2(a[y].y - a[x].y, a[y].x - a[x].x), v = std::acos(dis[x][y] / (d + d));
	return pr(upt(base - v), upt(base + v));
}
inline void up(double & x, double y) {
	if(x < y) {
		x = y;
	}
}
inline void reduce(std::vector<pr> & v) {
	if(v.size()) {
		std::vector<pr> t;
		sort(v.begin(), v.end());
		double L = v.front().first, R = v.front().second;
		for(const pr & x : v) {
			if(R < x.first) {
				t.emplace_back(L, R);
				L = x.first;
				R = x.second;
			} else {
				up(R, x.second);
			}
		}
		t.emplace_back(L, R);
		v.swap(t);
	}
}
inline bool check(int id, double x) {
	std::vector<pr> can, cannot;
	if(id <= n) {
		can.emplace_back(-pi, pi);
	} else {
		rep(i, 1, n) {
			if(dis[id][i] <= x + x - eps) {
				pr d = get(id, i, x);
				if(d.first <= d.second) {
					can.push_back(d);
				} else {
					can.emplace_back(d.first, pi);
					can.emplace_back(-pi, d.second);
				}
			}
		}
	}
	rep(i, n + 1, n + m) 
		if(dis[id][i] <= x + x - eps && i != id) {
			pr d = get(id, i, x);
			if(d.first <= d.second) {
				cannot.push_back(d);
			} else {
				cannot.emplace_back(d.first, pi);
				cannot.emplace_back(-pi, d.second);
			}
		}
	reduce(can), reduce(cannot);
	size_t i0 = 0, i1 = 0;
	for(;i0 < can.size();++i0) {
		for(;i1 < cannot.size() && cannot[i1].second + eps < can[i0].second;) 
			++ i1;
		if(i1 == cannot.size() || can[i0].first < cannot[i1].first - eps) return 1;
	}
	return 0;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n + m) {
		cin >> a[i].x >> a[i].y;
	}
	std::shuffle(a + 1, a + n + 1, rd);
	std::shuffle(a + n + 1, a + n + m + 1, rd);
	rep(i, 1, n + m) {
		rep(j, 1, n + m) {
			dis[i][j] = std::sqrt(sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y));
		}
	}
	double ans = 0;
	rep(i, 1, n + m) if(check(i, ans)) {
		double r = 1e9;
		for(int c = 0;c < 50;++c) {
			double mid = (ans + r) / 2;
			if(check(i, mid)) ans = mid;
			else r = mid;
		}
		if(ans > 9e8) {
			puts("-1");
			return 0;
		}
	}
	printf("%.10lf\n", ans);
}