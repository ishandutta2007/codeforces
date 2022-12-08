#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, m, a[N];
char s[N];
struct Node {
	int sum, pmn, pmx, smn, smx, lans, rans, ans, mx;
} t[N << 2];

#define lc (u << 1)
#define rc (u << 1 | 1)
#define mid ((l + r) >> 1)

void pushup(int u) {
	t[u].sum = t[lc].sum + t[rc].sum;
	t[u].pmn = min(t[lc].pmn, t[lc].sum + t[rc].pmn), t[u].pmx = max(t[lc].pmx, t[lc].sum + t[rc].pmx);
	t[u].smn = min(t[rc].smn, t[rc].sum + t[lc].smn), t[u].smx = max(t[rc].smx, t[rc].sum + t[lc].smx);
	t[u].lans = max(t[lc].lans, max(t[lc].mx + t[rc].pmx, -t[lc].sum + t[rc].lans));
	t[u].rans = max(t[rc].rans, max(t[rc].mx - t[lc].smn, t[rc].sum + t[lc].rans));
	t[u].ans = max(max(-t[lc].smn + t[rc].pmx, max(t[lc].rans + t[rc].pmx, -t[lc].smn + t[rc].lans)), max(t[lc].ans, t[rc].ans));
	t[u].mx = max(t[lc].mx + t[rc].sum, -t[lc].sum + t[rc].mx);	
}

void build(int u, int l, int r) {
	if(l == r) {
		t[u].sum = a[l];
		t[u].pmn = t[u].smn = min(a[l], 0);
		t[u].pmx = t[u].smx = max(a[l], 0);
		t[u].lans = t[u].rans = t[u].ans = t[u].mx = 1;
		return;
	}
	build(lc, l, mid), build(rc, mid + 1, r), pushup(u);
} 

void update(int u, int l, int r, int x) {
	if(l == r) {
		t[u].sum = a[l];
		t[u].pmn = t[u].smn = min(a[l], 0);
		t[u].pmx = t[u].smx = max(a[l], 0);
		t[u].lans = t[u].rans = t[u].ans = t[u].mx = 1;
		return;
	}
	if(x <= mid) update(lc, l, mid, x);
	else update(rc, mid + 1, r, x);
	pushup(u);
}

int main() {
	n = get() * 2 - 3, m = get();
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) a[i] = s[i] == '('? 1 : -1;
	build(1, 1, n);
	printf("%d\n", t[1].ans);
	for(int i = 1; i <= m; i++) {
		int x = get(), y = get();
		swap(a[x], a[y]), update(1, 1, n, x), update(1, 1, n, y);
		printf("%d\n", t[1].ans);
	}
	return 0;
}

/*
5 0
(()(()))
*/