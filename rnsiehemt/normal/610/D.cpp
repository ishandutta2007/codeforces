#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define nm ((nl+nr)/2)
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int inf = 1e9+1e5, Max = 1<<30, MaxNodes = 32*200*1000*2;

struct E {
	int type, y, l, r;
	E(int t, int y, int l, int r = 0) : type(t), y(y), l(l), r(r) { }
	bool operator<(const E &e) const {
		if (y == e.y) {
			if (type == e.type) return l < e.l;
			else return type < e.type;
		}else return y < e.y;
	}
};

struct RT {
	int n, sum[MaxNodes], lc[MaxNodes], rc[MaxNodes];
	RT() : n(1) { }
	void check(int &a) {
		if (!a) a = n++;
	}
	void update(int ui, int uv, int n = 0, int nl = -Max, int nr = Max) {
		if (ui == nl && nl+1 == nr) sum[n] += uv;
		else {
			sum[n] = 0;
			if (ui < nm) { check(lc[n]); update(ui, uv, lc[n], nl, nm);}
			else { check(rc[n]); update(ui, uv, rc[n], nm, nr);}
			if (lc[n]) sum[n] += sum[lc[n]];
			if (rc[n]) sum[n] += sum[rc[n]];
		}
	}
	int query(int ql, int qr, int n = 0, int nl = -Max, int nr = Max) {
		if (ql <= nl && nr <= qr) return sum[n];
		else {
			int s = 0;
			if (ql < nm && lc[n]) s += query(ql, qr, lc[n], nl, nm);
			if (nm < qr && rc[n]) s += query(ql, qr, rc[n], nm, nr);
			return s;
		}
	}
} rt;

int N;
std::vector<E> e;
std::set<std::pair<int, int>> s;
ll ans;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a > c) std::swap(a, c);
		if (b > d) std::swap(b, d);
		if (a == c) {
			e.push_back(E(0, b, a, d+1));
			e.push_back(E(1, d+1, a));
		} else {
			e.push_back(E(2, b, a, c));
		}
	}
	std::sort(e.begin(), e.end());
	int lasty = -inf, lastx = 420;
	for (E f : e) {
		if (f.type == 0) {
			auto it = s.lower_bound({f.l, -inf});
			if (it != s.end() && it->first == f.l) {
				if (f.r > it->second) {
					ans += f.r - it->second;
					//printf("hi x = %d, yhi = %d, ylo = %d\n", f.l, f.r, it->second);
					s.erase(it);
					s.insert({f.l, f.r});
				}
			} else {
				s.insert({f.l, f.r});
				//printf("ello x = %d, yhi = %d, ylo = %d\n", f.l, f.r, f.y);
				ans += f.r - f.y;
				rt.update(f.l, 1);
			}
		} else if (f.type == 1) {
			auto it = s.lower_bound({f.l, -inf});
			if (it != s.end() && it->first == f.l) {
				if (it->second == f.y) {
					s.erase(it);
					rt.update(f.l, -1);
				}
			}
		} else {
			if (lasty != f.y) {
				lastx = -inf;
			}
			lasty = f.y;
			if (f.r > lastx) {
				if (f.l <= lastx) f.l = lastx+1;
				ans += f.r - f.l - rt.query(f.l, f.r+1) + 1;
				lastx = f.r; 
			}
		}
	}
	printf("%lld\n", ans);
}