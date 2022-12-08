#include<bits/stdc++.h>
#define max(a,b) (a<b?b:a)
using namespace std;
 
int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}
 
const int N = 8e5 + 5, M = 1e3 + 5;
char opt[N]; 
int n, s[N], shit = 256, len, t, col[N], m, q;
int sa[N], rk[N], ht[N], id[N], cnt[N], p, f[N][32];
 
inline void GetSA() {
	for(int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
	for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
	for(int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;
	for(int w = 1; w < n && p < n; w <<= 1, m = p) {
		p = 0;
		for(int i = n - w + 1; i <= n; i++) id[++p] = i;
		for(int i = 1; i <= n; i++) if(sa[i] > w) id[++p] = sa[i] - w;
		for(int i = 1; i <= m; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++) ++cnt[rk[i]];
		for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
		for(int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i], id[i] = 0;
		swap(id, rk);
		rk[sa[1]] = 1, p = 1;
		for(int i = 2; i <= n; i++)
			rk[sa[i]] = (id[sa[i]] == id[sa[i - 1]] && id[sa[i] + w] == id[sa[i - 1] + w])? p : ++p;
	}
}
 
inline void GetHeight() {
	for(int i = 1, k = 0; i <= n; i++) {
		if(k) --k;
		while(s[i + k] == s[sa[rk[i] - 1] + k]) k++;
		ht[rk[i]] = k;
	}
}
 
void ST_init() {
	for(register int i = 1; i <= n; i++) f[i][0] = ht[i];
	for(register int j = 1; j <= 30; j++) 
		for(register int i = 1; i + (1 << j) - 1 <= n; i++)
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}
 
int ST_Query(int l, int r) {
	int len = floor(1.0 * log(r - l + 1) / log(2));
	return min(f[l][len], f[r - (1 << len) + 1][len]);
}
 
 
int S, occ[M][50005], tim[M], w[N];
 
struct Query { //  [l, r]   [x, y]  
	int x, y, l, r, id;
	inline bool operator < (Query x) const {
		return l/S == x.l / S? r < x.r : l < x.l;
	}
} ask[N];
 
int which(int x) { return (x - 1) / S + 1; }
 
void add(int x) {
	x = col[sa[x]];
	--occ[which(x)][w[x]++];
	++occ[which(x)][w[x]];
	tim[which(x)] = max(tim[which(x)], w[x]);
}
 
void del(int x) {
	x = col[sa[x]];
	--occ[which(x)][w[x]];
	if(!occ[which(x)][tim[which(x)]]) --tim[which(x)];
	++occ[which(x)][--w[x]];
}
 
struct mke_pair {
	int first, second;
	mke_pair() {}
	mke_pair(int a, int b) : first(a), second(b) {}
	inline bool operator < (mke_pair x) const {
		return second == x.second ? first > x.first : second < x.second;
	}
} ans[N];
 
mke_pair getans(int l, int r) {
	mke_pair ans = mke_pair(0x3fffffff,0);
	if(which(l) == which(r)) {
		for(int i = l; i <= r; ++i) ans = max(ans, mke_pair(i, w[i]));
		return ans;
	}
	int bl = which(l), br = which(r);
	int pos = which(t) + 1;
	for(int i = l; i <= bl * S; ++i) ans = max(ans, mke_pair(i, w[i]));
	for(int i = bl + 1; i < br; ++i) if(tim[i] > tim[pos]) pos = i;
	if(pos != which(t) + 1) for(int i = (pos - 1) * S + 1; i <= pos * S; ++i) ans = max(ans, mke_pair(i, w[i]));
	for(int i = (br - 1) * S + 1; i <= r; ++i) ans = max(ans, mke_pair(i, w[i]));
	return ans;
}
 
int main() {
	m = 256;
	scanf("%s", opt + 1); 
	len = strlen(opt + 1);
	for(int i = 1; i <= len; i++) s[++n] = opt[i] + 1; 
	s[++n] = ++m;
	t = get();
	for(int i = 1; i <= t; i++) {
		scanf("%s", opt + 1); 
		int w = strlen(opt + 1);
		for(int j = 1; j <= w; j++) s[++n] = opt[j] + 1, col[n] = i;
		s[++n] = ++m;
	}
	S = sqrt(n);
	GetSA();
	GetHeight();
	ST_init();
	memset(cnt, 0, sizeof(cnt));
	q = get();
	for(int i = 1; i <= q; i++) {
		int x = get(), y = get(), L = get(), R = get();
		ask[i].l = rk[L], ask[i].r = rk[L], ask[i].x = x, ask[i].y = y,ask[i].id=i;
		int l = 1, r = rk[L] - 1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(ST_Query(mid + 1, rk[L]) >= R - L + 1) ask[i].l = mid, r = mid - 1;
			else l = mid + 1;
		}
		l = rk[L] + 1, r = n;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(ST_Query(rk[L] + 1, mid) >= R - L + 1) ask[i].r = mid, l = mid + 1;
			else r = mid - 1;
		}
	}
	sort(ask + 1, ask + 1 + q);
	for(int i = 1, l = 1, r = 0; i <= q; i++) {
		while(r < ask[i].r) add(++r);
		while(l > ask[i].l) add(--l);
		while(r > ask[i].r) del(r--);
		while(l < ask[i].l) del(l++);
		ans[ask[i].id] = getans(ask[i].x, ask[i].y);
	}
	for(int i = 1; i <= q; i++) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}
 
/*
fu
2
fu
ift
2
1 2 1 2
1 2 1 1
*/