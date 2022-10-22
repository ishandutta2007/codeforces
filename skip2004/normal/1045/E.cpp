#include<bits/stdc++.h>
#define pb emplace_back
const int N = 10010;
using std::cin;
using std::cout;
struct T{ int x, y, c, id; };
typedef long long ll;
typedef std::vector<T> vc;
inline ll cross(const T & a, const T & b, const T & c) {
	return ll(b.x - a.x) * (c.y - a.y) - ll(c.x - a.x) * (b.y - a.y);
}
inline ll calc(const T & a, const T & b, const T & c) {
	return std::abs(cross(a, b, c));
}
inline bool in(const T & x, const T & a, const T & b, const T & c) {
	return calc(x, a, b) + calc(x, b, c) + calc(x, a, c) == calc(a, b, c);
}
std::vector<std::pair<int, int>> vec;
inline void solve(const T & x, const T & y, const T & z, vc & nd) {
	vc v; 
	for(T & a : nd) if(in(a, x, y, z) && a.id != x.id && a.id != y.id && a.id != z.id) v.pb(a);
	if(v.size()) { 
		for(T & x : v) if(x.c == z.c) std::swap(x, v.back());
		if(v.back().c == z.c) {
			const T mid = v.back(); v.pop_back();
			vec.pb(mid.id, z.id), solve(x, y, mid, v), solve(mid, z, x, v), solve(mid, z, y, v);
		} else {
			for(T & x : v) vec.pb(x.id, y.id);
		}
	}
}
int n;
inline vc get(vc v) {
	int x = 0;
	for(int i = 1;i < v.size();++i) {
		if(v[i].x < v[x].x || (v[i].x == v[x].x && v[i].y < v[x].y)) {
			x = i;
		}
	}
	std::swap(v[x], v.front());
	if(v.size() > 1) {
		sort(v.begin() + 1, v.end(), [&](const T & x, const T & y) { return cross(v.front(), x, y) > 0; });
	}
	static T st[N];
	int top = 0;
	for(const T & x : v) {
		for(;top > 1 && cross(st[top - 1], st[top], x) <= 0;) -- top;
		st[++top] = x;
	}
	return vc(st + 1, st + top + 1);
}
vc v;
inline void solve(vc & x) {
	int good = 1;
	for(auto o : v) if(o.c != x.front().c) {
		good = 0;
		for(int i = 0;i < x.size();++i) {
			if(i) 
				vec.emplace_back(x[i - 1].id, x[i].id);
			solve(x[i], x[(i + 1) % x.size()], o, v);
		}
		break;
	}
	if(good) {
		for(int i = 1;i < n;++i) {
			vec.emplace_back(0, i);
		}
	}
	cout << vec.size() << '\n';
	for(auto i : vec) {
		cout << i.first << ' ' << i.second << '\n';
	}
	exit(0);
}
int main() {
	cin >> n;
	for(int i = 1, x, y, c;i <= n;++i) {
		cin >> x >> y >> c;
		v.pb((T){x, y, c, i - 1});
	}
	vc x = get(v);
	auto is0 = [](const T & x){ return x.c == 0; };
	auto is1 = [](const T & x){ return x.c == 1; };
	for(int i = 0;i < n && x.front().c == 0;++i) {
		rotate(x.begin(), x.begin() + 1, x.end());
	}
	auto first = find_if(x.begin(), x.end(), is0);
	if(first != x.end())
		rotate(x.begin(), first, x.end());
	else
		solve(x);
	auto iter = find_if(x.begin(), x.end(), is1);
	if(find_if(iter, x.end(), is0) != x.end()) {
		cout << "Impossible" << '\n';
		return 0;
	}
	if(iter == x.end()) {
		solve(x);
	} else {
		auto i0 = x.begin(), i1 = iter;
		for(auto i = i0;i + 1 < i1;++i) {
			solve(*i, *(i + 1), *i1, v);
			vec.emplace_back(i -> id, (i + 1) -> id);
		}
		for(auto i = i1;i + 1 < x.end();++i) {
			solve(*i, *(i + 1), *i0, v);
			vec.emplace_back(i -> id, (i + 1) -> id);
		}
		cout << vec.size() << '\n';
		for(auto i : vec) {
			cout << i.first << ' ' << i.second << '\n';
		}
	}
	return 0;
}