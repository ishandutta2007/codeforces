//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n, m, a[N], s[N], nxt[N], ans[N];
map<int, int> mp;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Query {
	int l, r, id;
	friend bool operator < (const Query& a, const Query& b) {
		if(a.l != b.l) return a.l < b.l;
		return a.r < b.r;
	}
}q[N];
struct BIT {
	int c[N];
	int lowbit(int x) {return x & (-x);}
	void add(int x, int k) {for(;x<N;x+=lowbit(x)) c[x] ^= k;}
	int ask(int x) {int k = 0; for(;x;x-=lowbit(x)) k ^= c[x]; return k;}
}bit;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		s[i] = s[i-1] ^ a[i];
	}
	per(i, n, 1) {
		nxt[i] = mp[a[i]] ? mp[a[i]] : n + 1;
		mp[a[i]] = i;
	}
	for(auto it : mp) bit.add(it.second, it.first);
	scanf("%d", &m);
	rep(i, 1, m) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
	sort(q+1, q+1+m);
	int now = 1;
	rep(L, 1, n) {
		for(;now<=m&&q[now].l==L;now++) ans[q[now].id] = bit.ask(q[now].r) ^ s[q[now].r] ^ s[q[now].l-1];
		bit.add(L, a[L]);
		bit.add(nxt[L], a[L]);
	}
	rep(i, 1, m) printf("%d\n", ans[i]);
	return 0;
}