#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 300300;
int n;
char c[maxn];
int a[maxn];
int L, R, ans;
struct mes { int min, cnt; };
inline mes merge(const mes & x, const mes & y) {
	if(x.min != y.min) return x.min < y.min ? x : y;
	return (mes) {x.min, x.cnt + y.cnt};
}

mes pre[maxn], suf[maxn];

void init(int l, int r, const mes & oth) {
	pre[l - 1] = oth;
	suf[r + 1] = oth;
	for(int i = l;i <= r;++i) pre[i] = merge(pre[i - 1], (mes){ a[i], 1});
	for(int i = r;i >= l;--i) suf[i] = merge(suf[i + 1], (mes){ a[i], 1});
}
typedef std::pair<int, mes> pr;
inline int cmp0(const pr & x, const pr & y) {
	return x.second.min != y.second.min ? x.second.min < y.second.min : x.second.cnt > y.second.cnt;
}
inline void update(const pr & x, const pr & y, const mes & other) {
	const auto res = merge(other, merge(x.second, y.second));
	if(res.cnt > ans) {
		ans = res.cnt;
		L = x.first;
		R = y.first;
	}
}
inline void update(std::vector<pr> & v0, std::vector<pr> & v1, const mes & other) {
	int i1 = 0;
	for(const auto & x : v0) {
		for(;i1 < (int) v1.size() && v1[i1].second.min < x.second.min;++i1);
		if(i1 != (int) v1.size()) update(x, v1[i1], other);
	}
}
inline void solve(std::vector<pr> & v0, std::vector<pr> & v1, const mes & other) {
	sort(v0.begin(), v0.end(), cmp0);
	sort(v1.begin(), v1.end(), cmp0);
	update(v0, v1, other);
	update(v1, v0, other);
}
void solve(int l, int r, mes other) {
	if(l == r) return ;
	int mid = l + r >> 1;
	mes left = other, right = other;
	for(int i = mid + 1;i <= r;++i) left = merge(left, (mes){ a[i], 1});
	for(int i = l;i <= mid;++i) right = merge(right, (mes){ a[i], 1});
	solve(l, mid, left);
	solve(mid + 1, r, right);
	init(l, mid, (mes){ n, 0 });
	std::vector<pr> v00, v01, v10, v11;
	for(int i = l;i <= mid;++i)
		if(c[i] == '(') {
			v00.emplace_back(i, merge(pre[i - 1], (mes){ suf[i].min - 2, suf[i].cnt}));
		} else {
			v01.emplace_back(i, merge(pre[i - 1], (mes){ suf[i].min + 2, suf[i].cnt}));
		}
	init(mid + 1, r, (mes){ n, 0 });
	for(int i = mid + 1;i <= r;++i) {
		if(c[i] == ')') {
			v10.emplace_back(i, merge(suf[i], (mes){ pre[i - 1].min - 2, pre[i - 1].cnt}));
		} else {
			v11.emplace_back(i, merge(suf[i], (mes){ pre[i - 1].min + 2, pre[i - 1].cnt}));
		}
	}
	solve(v00, v10, other);
	solve(v01, v11, other);
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> c + 1;
	for(int i = 1;i <= n;++i) {
		a[i] = a[i - 1] + (c[i] == '(' ? 1 : -1);
	}
	L = 1, R = 1, ans = std::count(a + 1, a + n + 1, * std::min_element(a + 1, a + n + 1));
	if(a[n] == 0) {
		solve(1, n, {n, 0});
	} else {
		ans = 0;
	}
	cout << ans << '\n';
	cout << L << ' ' << R << '\n';
}