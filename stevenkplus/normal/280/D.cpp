#include <cstdio>
#include <algorithm>
#include <vector>

#include <iostream>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> range;
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
#define pb push_back

const int MAXN = 1 << 17;
const int SIZE = MAXN << 1;

int ar[MAXN];

range operator+ (range &a, range &b) {
	return range(a.first + b.first, pii(a.second.first, b.second.second));
}

range operator- (range &r) {
	return range(-r.first, r.second);
}

struct node {
	range lm, rm, mm, lM, rM, mM, S;
	bool flipped;
	node(int v, int idx) {
		flipped = false;
		range val(v, pii(idx, idx + 1));
		range lv(0, pii(idx, idx));
		range rv(0, pii(idx + 1, idx + 1));
		lm = min(lv, val);
		rm = min(rv, val);
		lM = max(lv, val);
		rM = max(rv, val);

		mm = min(lm, rm);
		mM = max(lM, rM);
		S = val;
	}
	node() {
		mM = range(-1, pii(0, 0));
	}
};

node null;

node operator+ (node &a, node &b) {
	if (a.mM.first == -1) return b;
	if (b.mM.first == -1) return a;
	node ret;
	ret.lm = min(a.lm, a.S + b.lm);
	ret.rm = min(b.rm, a.rm + b.S);
	ret.mm = min(min(a.mm, b.mm), a.rm + b.lm);
	ret.lM = max(a.lM, a.S + b.lM);
	ret.rM = max(b.rM, a.rM + b.S);
	ret.mM = max(max(a.mM, b.mM), a.rM + b.lM);
	ret.S = a.S + b.S;
	ret.flipped = false;
	return ret;
}

node seg[SIZE];

node flip(node n) {
	node ret;
	ret.flipped = !n.flipped;
	ret.lm = -n.lM;
	ret.rm = -n.rM;
	ret.mm = -n.mM;
	ret.lM = -n.lm;
	ret.rM = -n.rm;
	ret.mM = -n.mm;
	ret.S = -n.S;
	return ret;
}

void down(int cur) {
	int childl = cur * 2, childr = childl + 1;
	if (childl < SIZE) {
		if (seg[cur].flipped) {
			seg[childl] = flip(seg[childl]);
			seg[childr] = flip(seg[childr]);
		}
		seg[cur] = seg[childl] + seg[childr];
	}
	seg[cur].flipped = false;
}

void build(int cur = 1, int l = 0, int r = MAXN) {
	if (l + 1 == r) {
		seg[cur] = node(ar[l], l);
	} else {
		if (seg[cur].flipped) down(cur);
		int childl = cur * 2, childr = childl + 1;
		int mid = (l + r) / 2;
		build(childl, l, mid);
		build(childr, mid, r);
		down(cur);
	}
}

void update(int idx, int val, int cur = 1, int l = 0, int r = MAXN) {
	if (l <= idx && idx < r) {
		down(cur);
		if (l + 1 == r) {
			seg[cur] = node(val, idx);
		} else {
			int childl = cur * 2, childr = childl + 1;
			int mid = (l + r) / 2;
			update(idx, val, childl, l, mid);
			update(idx, val, childr, mid, r);
		}
		down(cur);
	}
}

void reverse(int left, int right, int cur = 1, int l = 0, int r = MAXN) {
	if (r <= left || l >= right) return;
	if (left <= l && r <= right) {
		seg[cur] = flip(seg[cur]);
	} else {
		int childl = cur * 2, childr = childl + 1;
		int mid = (l + r) / 2;
		reverse(left, right, childl, l, mid);
		reverse(left, right, childr, mid, r);
		down(cur);
	}
}

node ask(int left, int right, int cur = 1, int l = 0, int r = MAXN) {
	if (r <= left || l >= right) return null;
	if (left <= l && r <= right) {
		return seg[cur];
	} else {
		if (seg[cur].flipped) {
			down(cur);
		}
		int childl = cur * 2, childr = childl + 1;
		int mid = (l + r) / 2;
		node n1 = ask(left, right, childl, l, mid);
		node n2 = ask(left, right, childr, mid, r);
		return n1 + n2;
	}
}

ostream& operator<< (ostream &c, pii &p) {
	return c << "(" << p.first << "," << p.second << ")";
}

ostream& operator<< (ostream &c, range &p) {
	return c << "(" << p.first << "," << p.second << ")";
}

ostream& operator<< (ostream &c, node &n) {
	return c << n.flipped << " " << n.mM;
}

void disp(int cur = 1, int l = 0, int r = MAXN) {
	int childl = cur * 2, childr = childl + 1;
	int mid = (l + r) / 2;
	cout << "[" << l << "," << r << "] (" << cur << ") = " << seg[cur] << "\n";
	if (l + 1 == r) return;
	disp(childl, l, mid);
	disp(childr, mid, r);
}

int N, M;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}
	build();

	scanf("%d", &M);
	for(int i = 0; i < M; ++i) {
// disp();
		int qtype;
		scanf("%d", &qtype);
		if (qtype == 0) {
			int idx, val;
			scanf("%d %d", &idx, &val);
			--idx;
			update(idx, val);
		} else if (qtype == 1) {
			int l, r, k;
			scanf("%d %d %d", &l, &r, &k);
			--l;
			vector<range> revrange;

			int sum = 0;
			for(int j = 0; j < k; ++j) {
				range ans = ask(l, r).mM;
//	cout << ans << endl;
				sum += ans.first;
				reverse(ans.second.first, ans.second.second);
//	cout << "reversing.\n";
				revrange.pb(ans);
//	disp();
			}

			repi(j, revrange) {
				reverse(j->second.first, j->second.second);
			}

			printf("%d\n", sum);
		}
	}

	return 0;
}