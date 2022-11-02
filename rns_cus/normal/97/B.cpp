#include <bits/stdc++.h>
using namespace std;

#define N 200010

struct pnt{
	int x, y;
	pnt() {}
	pnt(int _x, int _y) : x(_x), y(_y) {}
	bool operator < (const pnt &p) const{
		return x == p.x ? y < p.y : x < p.x;
	}
	bool operator == (const pnt &p) const {
		return x == p.x && y == p.y;
	}
	void input() { scanf("%d %d", &x, &y); }
	void print() { printf("%d %d\n", x, y); }
}p[N], q[N];

int n, m;

void solve(int st, int en) {
	if(en < st) return;
	int mid = (st + en) >> 1;
	for (int i = st; i <= en; i ++) q[m ++] = {p[mid].x, p[i].y};
	solve(st, mid - 1);
	solve(mid + 1, en);
}

int main() {
	///freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) p[i].input();
	sort(p + 1, p + n + 1);
	solve(1, n);
	sort(q, q + m);
	m = unique(q, q + m) - q;
	cout << m << endl;
	for (int i = 0; i < m; i ++) {
		q[i].print();
	}
}