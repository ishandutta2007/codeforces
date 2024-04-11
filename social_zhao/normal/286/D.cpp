#include<bits/stdc++.h>
#define int long long
#define IT set<Segment>::iterator
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, m; 
struct Segment {
	int l, r, t;
	Segment(int a = 0, int b = 0, int c = 0) { l = a, r = b, t = c; }
	bool operator <(Segment b) const { return l < b.l; }
} seg[N];
set<Segment> s;
struct Delta { int x, id; } bin[N * 10];
int tot, ans[N];

IT split(int pos) {
	IT it = s.lower_bound(Segment(pos, 0, 0));
	if(it != s.end() && it -> l == pos) return it;
	--it;
	int l = it -> l, r = it -> r, t = it -> t;;
	s.erase(it), s.insert(Segment(l, pos - 1, t)); 
	return s.insert(Segment(pos, r, t)).first;
}

void assign(int l, int r, int v) {
	IT itr = split(r + 1), itl = split(l);
	s.erase(itl, itr), s.insert(Segment(l, r, v));
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	n = get(), m = get();
	for(int i = 1; i <= m; i++) seg[i].l = get(), seg[i].r = get() - 1, seg[i].t = get();
	sort(seg + 1, seg + 1 + m, [](Segment a, Segment b) { return a.t > b.t; });
	s.insert(Segment(0, 1e9, 2e9));
	for(int i = 1; i <= m; i++) 
		assign(seg[i].l, seg[i].r, seg[i].t);
	for(auto v: s) {
		int l = v.l, r = v.r + 1, t = v.t;
		if(l == r || t == 2e9) continue;
//		cout << "Segment: " << l << " " << r << " " << t << endl;
		bin[++tot] = (Delta){ t - r, 0 };
		bin[++tot] = (Delta){ t - l, -1 };
	}
	for(int i = 1, x; i <= n; i++) x = get(), bin[++tot] = (Delta){ x, i };
	sort(bin + 1, bin + 1 + tot, [](Delta a, Delta b) { return a.x < b.x; });
	int lst = -1e9, now = 0, delt = 0;
	for(int i = 1; i <= tot; i++) {
		now += delt * (bin[i].x - lst);
		if(bin[i].id > 0) ans[bin[i].id] = now;
		else delt += bin[i].id * 2 + 1;
		lst = bin[i].x;
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << endl;
	return 0;
}