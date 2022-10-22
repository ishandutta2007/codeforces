#include<bits/stdc++.h>
using std::cin;
using std::cout;
typedef double db;
const int maxn = 200100;
typedef std::pair<db, db> pr;
const db pi = std::acos(-1), inf = 1. / 0;
int n, m;
struct node {
	int x, y;
} a[maxn];
inline db sqr(db x){ return x * x; }
inline db abs(const node & x) { return sqrt(sqr(x.x) + sqr(x.y)); }
db min_d;
int good[maxn];
int go[20][maxn];
inline bool can(db R) {
	std::vector<pr> vec, vc; vec.reserve(n + n), vc.reserve(n + n);
	for(int i = 0;i < n;++i) {
		const db x = atan2(a[i].y, a[i].x), y = acos(R / abs(a[i]));
		if(x - y < 0) {
			vec.push_back(pr(x - y + pi + pi, x + y + pi + pi));
		} else {
			vec.push_back(pr(x - y, x + y));
		}
		good[i] = 1;
	}
	sort(vec.begin(), vec.end());
	for(int i = 0;i < n;++i) {
		pr x = vec[i];
		x.first += pi + pi;
		x.second += pi + pi;
		vec.push_back(x);
	}
	static int stack[maxn];
	int top = 0;
	for(int i = 0;i < n + n;++i) {
		for(;top && vec[stack[top]].second >= vec[i].second;) good[stack[top] < n ? stack[top] : stack[top] - n] = 0, -- top;
		stack[++top] = i;
	}
	int N = 0;
	for(int i = 0;i < n;++i) if(good[i]) {
		vc.push_back(vec[i]), ++ N;
	}
	for(int i = 0;i < N;++i) {
		pr x = vc[i];
		x.first += pi + pi;
		x.second += pi + pi;
		vc.push_back(x);
	}
	for(int i = 0;i < N + N;++i) {
		go[0][i] = std::upper_bound(vc.begin(), vc.end(), pr(vc[i].second, 0)) - vc.begin();
	}
	go[0][N + N] = N + N;
	for(int i = 1;i < 19;++i) {
		for(int j = 0;j <= N + N;++j) {
			go[i][j] = go[i - 1][go[i - 1][j]];
		}
	}
	for(int i = 0;i < N;++i) {
		int to = i;
		for(int T = m;T;T &= T - 1) {
			to = go[__builtin_ctz(T)][to];
		}
		if(to - i >= N) return 1;
	}
	return 0;
}
int main() {
	min_d = inf;
	cin >> n >> m;
	for(int i = 0;i < n;++i) {
		cin >> a[i].x >> a[i].y;
		min_d = std::min(min_d, abs(a[i]));
	}
	db l = 0, r = min_d;
	for(int i = 0;i < 50;++i) {
		db mid = (l + r) / 2;
		if(can(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	printf("%.10lf\n", l);
}