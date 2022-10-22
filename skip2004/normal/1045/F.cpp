#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 200200;
typedef long long ll;
struct pr { int x, y, id; } P;
ll cross(const pr & a, const pr & b) { return (ll) a.x * b.y - (ll) a.y * b.x; }
ll cross(const pr & a, const pr & b, const pr & c) { return ll(b.x - a.x) * (c.y - a.y) - ll(c.x - a.x) * (b.y - a.y); }
inline ll abs(const pr & a){ return (ll) a.x * a.x + (ll) a.y * a.y; }
inline bool cmp0(const pr & x, const pr & y) {
	ll cs = cross(P, x, y);
	if(cs != 0) return cs > 0;
	ll cx = abs(x), cy = abs(y);
	return cx != cy ? cx < cy : x.id < y.id;
}
typedef std::vector<pr> vec;
inline vec chk(std::vector<pr> & vec) {
	int min = 0;
	for(int i = 1;i < vec.size();++i) {
		if(vec[min].x > vec[i].x || (vec[min].x == vec[i].x && vec[min].y > vec[i].y)) {
			min = i;
		}
	}
	std::swap(vec[0], vec[min]);
	if(vec.size() > 1) P = vec[0], sort(vec.begin() + 1, vec.end(), cmp0);
	static pr st[maxn]; int top = 0;
	for(int i = 0;i < vec.size();++i) {
		for(;top > 1 && cross(st[top - 1], st[top], vec[i]) <= 0;) -- top;
		st[++top] = vec[i];
	}
	for(int i = 1;i <= top;++i) if(st[i].x % 2 || st[i].y % 2) return {};
	return ::vec(st + 1, st + top + 1);
}
int n;
pr a[maxn];
int good[maxn];
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n, ++ n;
	for(int i = 1;i < n;++i) {
		cin >> a[i].x >> a[i].y, a[i].id = i;
		if(a[i].x == 0 && a[i].y == 0) { -- n, -- i; continue; }
	}
	vec T = vec(a, a + n);
	vec v = chk(T);
	if(v.empty()) {
		cout << "Ani" << '\n';
		return 0;
	}
	for(int i = 2;i < v.size();i += 2) good[v[i].id] = 1;
	vec t;
	for(int i = 0;i < n;++i) if(!good[i]) t.push_back(a[i]);
	if(chk(t).empty()) {
		cout << "Ani" << '\n';
		return 0;
	}
	for(int i = 2;i < v.size();i += 2) good[v[i].id] = 0;
	for(int i = 1;i < v.size();i += 2) good[v[i].id] = 1;
	t.clear();
	for(int i = 0;i < n;++i) if(!good[i]) t.push_back(a[i]);
	if(chk(t).empty()) {
		cout << "Ani" << '\n';
		return 0;
	}
	cout << "Borna" << '\n';
}