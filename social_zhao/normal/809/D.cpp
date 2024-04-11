#include<bits/stdc++.h>
#define lc (ch[x][0])
#define rc (ch[x][1])
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5, M = 3e6 + 5;
int n, l[N], r[N];
int ch[N][2], p[N], val[N], tot, rt, tag[N], cnt[N];

void pusha(int x, int v) {
	tag[x] += v, val[x] += v;
}

void pushdown(int x) {
	if(!tag[x]) return;
	if(lc) pusha(lc, tag[x]);
	if(rc) pusha(rc, tag[x]);
	tag[x] = 0;
}

void split(int x, int k, int &u, int &v) {
	pushdown(x);
	if(!x) return (void)(u = v = 0);
	if(val[x] <= k) u = x, split(rc, k, rc, v);
	else v = x, split(lc, k, u, lc);
}

int merge(int x, int y) {
	pushdown(x), pushdown(y);
	if(!x || !y) return x + y;
	if(p[x] < p[y]) { ch[x][1] = merge(ch[x][1], y); return x; }
	else { ch[y][0] = merge(x, ch[y][0]); return y; }
}

void insert(int num) {
	int a, b;
	split(rt, num, rt, a);     // Split the whole tree into A(<= k) and B(>k)
	split(rt, num - 1, rt, b); // Split tree A into C(<k) and D(k)
	if(b) cnt[b]++;
	else b = ++tot, val[b] = num, p[b] = rand(), cnt[b] = 1, ch[b][1] = ch[b][0] = 0;
	rt = merge(rt, b), rt = merge(rt, a);
}

void del(int num) {
	int a, b;
	split(rt, num, rt, a);
	split(rt, num - 1, rt, b);
	if(cnt[b] > 1) cnt[b]--, rt = merge(rt, b), rt = merge(rt, a);
	else rt = merge(rt, a);
}

void add(int x, int y) {
	int a, b;
	split(rt, y, rt, b), split(rt, x - 1, rt, a);
	if(a) pusha(a, 1);
	rt = merge(rt, a), rt = merge(rt, b);
}

int querysuf(int v) {
	int x = rt, ans = 0;
	while(x) {
		pushdown(x);
		if(val[x] < v) x = rc;
		else ans = x, x = lc;
	}
	return ans;
}

int ans = 0;

void dfs(int x) {
	if(!x) return;
	ans += cnt[x];
	dfs(lc), dfs(rc);
}

void debug(int x) {
	if(!x) return;
	pushdown(x);
	debug(lc);
	printf("%d ", val[x]);
	debug(rc);
}

int main() {
	n = get();
	for(int i = 1; i <= n; i++) l[i] = get(), r[i] = get();
	insert(l[1]);
	for(int i = 2; i <= n; i++) {
		int s = querysuf(r[i]);
		if(s) del(val[s]);
		add(l[i], r[i] - 1);
		insert(l[i]);
		//printf("%d : ", i); debug(rt); printf("\n");
	}
	dfs(rt);
	printf("%d\n", ans);
	return 0;
}