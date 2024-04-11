#include<bits/stdc++.h>
typedef long long ll;
typedef long double db;
using std::cin;
using std::cout;
struct pt { db x, y; } node;

inline bool operator == (const pt & x, const pt & y) {
	return x.x == y.x && x.y == y.y;
}
inline db cross(const pt & x, const pt & y, const pt & z) {
	return (y.x - x.x) * (z.y - x.y) - (z.x - x.x) * (y.y - x.y);
}

inline bool cmp0(const pt & x, const pt & y) {
	return cross(node, x, y) < 0;
}
inline bool cmp1(const pt & x, const pt & y) {
	return x.x < y.x;
}

db max;

struct mat {
	db a[3][3];
	inline mat() { memset(a, 0, sizeof a); }
	inline mat operator * (const mat & b) const {
		mat ret;
		for(int i = 0;i < 3;++i) {
			for(int j = 0;j < 3;++j) {
				for(int k = 0;k < 3;++k) {
					ret.a[i][k] += a[i][j] * b.a[j][k];
				}
			}
		}
		return ret;
	}
};
inline mat to_mat(db a00, db a01, db a02, db a10, db a11, db a12, db a20, db a21, db a22) {
	mat ret;
	ret.a[0][0] = a00, ret.a[0][1] = a01, ret.a[0][2] = a02;
	ret.a[1][0] = a10, ret.a[1][1] = a11, ret.a[1][2] = a12;
	ret.a[2][0] = a20, ret.a[2][1] = a21, ret.a[2][2] = a22;
	return ret;
}
inline mat to_mat(const pt & i) {
	return to_mat(1, i.x * max, 0, 0, 1 - i.x, 0, 1, i.y, 1);
}
const mat I = to_mat(1, 0, 0, 0, 1, 0, 0, 0, 1);
std::vector<pt> vec;
int n;
ll t;
mat power[100];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> t;
	for(int i = 0, a, b;i < n;++i) {
		db p;
		cin >> a >> b >> p;
		max = std::max<db>(max, b * p);
		vec.push_back((pt){(db) p, a * p});
	}
	sort(vec.begin(), vec.end(), cmp1);
	std::vector<pt> hull;
	for(const pt & i : vec) {
		for(;hull.size() > 1 && cross(hull[hull.size() - 2], hull.back(), i) >= 0;) {
			hull.pop_back();
		}
		hull.push_back(i);
	}
	mat res = to_mat(0, 0, 1, 0, 0, 0, 0, 0, 0);
	// reverse(hull.begin(), hull.end());
	for(int i = 0;i < hull.size();++i) {
		const pt m0 = hull[i], m1 = i == hull.size() - 1 ? m0 : hull[i + 1];
		power[0] = to_mat(m0);
		for(int i = 1;i < 35;++i) {
			power[i] = power[i - 1] * power[i - 1];
		}
		const auto check = [&](const mat&M, const pt&x, const pt&y) {
			if(x == y) return true;
			const db t = M.a[0][0], s = M.a[0][1];
			return (t * max - s) * (x.x - y.x) >= (y.y - x.y);
		};
		for(int i = 34;i >= 0;--i) {
			if(1ll << i <= t) {
				mat x = res * power[i];
				if(check(x, m0, m1)) {
					res = x;
					t -= 1ll << i;
				}
			}
		}
		if(t) {
			if(check(res, m0, m1)) {
				res = res * power[0];
				-- t;
			}
		}
	}
	printf("%.10Lf\n", res.a[0][1]);
}