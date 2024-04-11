#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

class T {
private:
	struct nd {
		int x, y, z;
		int ma, sz, w;
		nd* c[2];
		nd() {}
		nd(int x, int y, int z, nd*n): x(x), y(y), z(z), w(rand()), ma(x), sz(1) {
			c[0] = c[1] = n;
		}
		void rz() {
			sz = c[0]->sz + c[1]->sz + 1;
			ma = max(x, max(c[0]->ma, c[1]->ma));
		}
	}*u, *h;

	void rt(nd*&p, bool t) {
		nd*q=p->c[t];
		p->c[t]=q->c[!t];
		q->c[!t]=p;
		p->rz();
		q->rz();
		p = q;
	}

	void ins(nd*&p, int x, int y, int z) {
		if (p == u) {
			p = new nd(x, y, z, u);
			return;
		}
		bool t = !(y >= 1 + p->c[1]->sz && x > max(p->x, p->c[1]->ma));
		if (!t) ins(p->c[t], x, y-(1+p->c[1]->sz), z);
		else ins(p->c[t], x, y, z);
		if (p->c[t]->w < p->w) rt(p, t);
		else p->rz();
	}

	void out(nd*p, vector<int>&s) {
		if (p == u) return;
		out(p->c[0], s);
		s.pb(p->z);
		out(p->c[1], s);
	}

public:
	T() {
		u = new nd(0, 0, 0, nullptr);
		u->sz = 0;
		h = u;
	}

	void ins(int x, int y, int z) {
		ins(h, x, y, z);
	}
	
	vector<int> out() {
		vector<int> s;
		out(h, s);
		return s;
	}
}*t;

int n;

int main() {
	cin >> n;
	t = new T();
	for (int i = 0; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		t->ins(x, y, i);
	}
	auto s = t->out();
	for (int i = 0; i < n; i ++)
		printf("%d%c", s[i]+1, i == n-1?'\n':' ');
	return 0;
}