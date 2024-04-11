// LUOGU_RID: 95054922
// Problem: E. William The Oblivious
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int a, b, c, noab, nobc, noabc;
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void pushup(int u) {
		t[u].a = t[lc(u)].a + t[rc(u)].a;
		t[u].b = t[lc(u)].b + t[rc(u)].b;
		t[u].c = t[lc(u)].c + t[rc(u)].c;
		t[u].noab = min(t[lc(u)].a + t[rc(u)].noab, t[lc(u)].noab + t[rc(u)].b);
		t[u].nobc = min(t[lc(u)].b + t[rc(u)].nobc, t[lc(u)].nobc + t[rc(u)].c);
		t[u].noabc = min({t[lc(u)].a + t[rc(u)].noabc, t[lc(u)].noab + t[rc(u)].nobc, t[lc(u)].noabc + t[rc(u)].c});
	}
	void build(char* s, int u, int l, int r) {
		if(l == r) {
			t[u].a = s[l] == 'a';
			t[u].b = s[l] == 'b';
			t[u].c = s[l] == 'c';
			t[u].noab = 0;
			t[u].nobc = 0;
			t[u].noabc = 0;
			return;
		}
		int mid = (l + r) >> 1;
		build(s, lc(u), l, mid);
		build(s, rc(u), mid+1, r);
		pushup(u);
	}
	void modify(int u, int l, int r, int pos, char c) {
		if(l == r) {
			s[l] = c;
			t[u].a = s[l] == 'a';
			t[u].b = s[l] == 'b';
			t[u].c = s[l] == 'c';
			t[u].noab = 0;
			t[u].nobc = 0;
			t[u].noabc = 0;
			return;
		}
		int mid = (l + r) >> 1;
		if(pos <= mid) modify(lc(u), l, mid, pos, c);
		else modify(rc(u), mid+1, r, pos, c);
		pushup(u);
	}
	#undef lc
	#undef rc
}sgt;

int main() {
	scanf("%d%d%s", &n, &m, s+1);
	sgt.build(s, 1, 1, n);
	while(m--) {
		int i; char c[2];
		scanf("%d%s", &i, c);
		sgt.modify(1, 1, n, i, c[0]);
		printf("%d\n", sgt.t[1].noabc);
	}
	return 0;
}