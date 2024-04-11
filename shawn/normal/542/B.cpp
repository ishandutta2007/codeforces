#include <cstdio>
#include <queue>
#include <algorithm>

#define fi first
#define se second
#define mk make_pair
#define For(i, j, k) for (int i = j; i <= k; i ++)

using namespace std;
typedef pair<int, int> PII;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}
const int val = 1e9;
const int maxn = 6e6;
priority_queue <PII> q;
int n, k, pre = -1;

namespace Segment{
	struct tree{
		int mx, w, ls, rs;
	}tr[maxn];
	int rt, tot;

	void pushup(int k) {
		tr[k].mx = max(tr[tr[k].ls].mx, tr[tr[k].rs].mx) + tr[k].w;
	}
	
	void update(int &k, int l, int r, int x, int y) {
		if (!k) k = ++tot;
		if (l == r - 1) {
			tr[k].w = tr[k].mx = y;
			return;
		}
		
		int mid = l + r >> 1;
		if (x < mid) update(tr[k].ls, l, mid, x, y);
		else update(tr[k].rs, mid, r, x, y);
		pushup(k);
	}
	
	void add(int &k, int l, int r, int x, int y) {
		if (!k || y <= l || r <= x) return;
		if (x <= l && r <= y) {
			tr[k].mx ++;
			tr[k].w ++;
			return;
		}
		
		int mid = l + r >> 1;
		add(tr[k].ls, l, mid, x, y);
		add(tr[k].rs, mid, r, x, y);
		pushup(k);
	}
	
	int query(int k, int l, int r, int x, int y) {
		if (!k || y <= l || r <= x) return 0;
		if (x <= l && r <= y) return tr[k].mx;
		
		int mid = l + r >> 1;
		int ret = max(query(tr[k].ls, l, mid, x ,y), query(tr[k].rs, mid, r, x, y));
		return tr[k].w + ret;
	}
	
};

int main() {
//	freopen("hunt.in", "r", stdin);
//	freopen("hunt.out", "w", stdout);
	n = read(), k = read();
	For(i, 1, n) {
		int l = read(), r = read();
		l = max(0, l);
		q.push(mk(-r, -l));
		q.push(mk(-l, 1));
	}
	
	using namespace Segment;
	
	while (!q.empty()) {
		int l = -q.top().se, r = -q.top().fi;
		q.pop();
		if (l >= 0) add(rt, 0, val, l, r + 1);
		else {
			if (r == pre) continue;
			int u = query(rt, 0, val, pre, pre + 1);
			int v = query(rt, 0, val, 0, r - k + 1);
		//	printf("%d %d\n",u, v);
			if (l == -1 || u < v) {
				pre = r;
				update(rt, 0, val, r, v);
				if (r + k <= val) q.push(mk(- r - k, 2));
			}
		}
	}
	
	printf("%d", tr[1].mx);
	return 0;
}