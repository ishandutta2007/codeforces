#include<bits/stdc++.h>
#define mid ((l + r) >> 1)
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5;
int n, a[N], b[N], L[N], R[N];
vector<int> bin[N];
int T[N], sum[N * 20], lc[N * 20], rc[N * 20], tot;

int update(int pre, int l, int r, int x) {
	int rt = ++tot;
	lc[rt] = lc[pre], rc[rt] = rc[pre], sum[rt] = sum[pre] + 1;
	if(l == r) return rt;
	if(x <= mid) lc[rt] = update(lc[pre], l, mid, x);
	else rc[rt] = update(rc[pre], mid + 1, r, x);
	return rt;
}

int query(int u, int v, int l, int r, int a, int b) {
	if(a == l && r == b) return sum[v] - sum[u];
	if(b <= mid) return query(lc[u], lc[v], l, mid, a, b);
	else if(a > mid) return query(rc[u], rc[v], mid + 1, r, a, b);
	else return query(lc[u], lc[v], l, mid, a, mid) + query(rc[u], rc[v], mid + 1, r, mid + 1, b);
}

int count(int D, int U, int L, int R) {
	if(D > U || L > R) return 0;
	return query(T[D - 1], T[U], 1, 2 * n, L, R);
}

signed main() {
	n = get();
	for(int i = 1; i <= n; i++) {
		a[i] = get(), b[i] = get();
		if(a[i] > b[i]) swap(a[i], b[i]);
		bin[a[i]].push_back(b[i]);
	}
	for(int i = 1; i <= 2 * n; i++) {
		T[i] = T[i - 1];
		for(auto v : bin[i]) T[i] = update(T[i], 1, 2 * n, v);
	}
	int ans = n * (n - 1) * (n - 2) / 6, sum1 = 0, sum2 = 0;
	for(int i = 1; i <= n; i++) {
		L[i] = count(1, a[i] - 1, 1, a[i] - 1)
		     + count(1, a[i] - 1, b[i] + 1, 2 * n)
			 + count(b[i] + 1, 2 * n, b[i] + 1, 2 * n);
		R[i] = count(a[i] + 1, b[i] - 1, a[i] + 1, b[i] - 1);
		sum1 += L[i] * R[i];
		sum2 += (L[i] + R[i]) * (n - L[i] - R[i] - 1);
	}
	sum2 /= 2;
	ans -= sum1 + sum2;
	cout << ans;
	return 0;
}