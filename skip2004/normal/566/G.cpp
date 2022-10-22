#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;

int n, m, p;

struct pt { int a, b; };

inline int operator == (const pt & x, const pt & y) {
	return x.a == y.a && x.b == y.b;
}

inline ll cross(const pt & x, const pt & y, const pt & z) {
	return ll(y.a - x.a) * (z.b - x.b) - ll(z.a - x.a) * (y.b - x.b);
}

inline std::vector<pt> get(std::vector<pt> vec, int u = 0) {
	if(u) {
		int maxa = 0, maxb = 0;
		for(pt x : vec) {
			maxa = std::max(maxa, x.a);
			maxb = std::max(maxb, x.b);
		}
		vec.push_back((pt){ maxa, 0 });
		vec.push_back((pt){ 0, maxb });
	}
	sort(vec.begin(), vec.end(), [](pt x, pt y) { return x.a == y.a ? x.b > y.b : x.a < y.a; });
	std::vector<pt> res;
	for(pt x : vec) {
		for(;res.size() >= 2 && cross(res[res.size() - 2], res.back(), x) >= !u;)
			res.pop_back();
		res.push_back(x);
	}
	return res;
}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> p >> p;
	std::vector<pt> A(n);
	std::vector<pt> B(m);
	for(pt & x : A) cin >> x.a >> x.b;
	for(pt & x : B) cin >> x.a >> x.b;
	A = get(A, 1);
	B = get(B, 1);
	std::vector<pt> C = B;
	C.insert(C.end(), A.begin(), A.end());
	if(get(C) == B) {
		cout << "Min" << '\n';
	} else {
		cout << "Max" << '\n';
	}
}