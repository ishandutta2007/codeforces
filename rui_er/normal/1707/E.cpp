// LUOGU_RID: 90368829
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m, a[N], lg[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Segment { // Sparse Table
	int l, r;
	Segment(int a=0, int b=0) : l(a), r(b) {}
	friend bool operator==(const Segment& a, const Segment& b) {
		return a.l == b.l && a.r == b.r;
	}
	friend Segment operator+(const Segment& a, const Segment& b) {
		return Segment(min(a.l, b.l), max(a.r, b.r));
	}
	bool ok() {
		return *this == Segment(1, n);
	}
}st[N][30][18];
Segment query(int d, int l, int r) {
	if(l >= r) return Segment(n, 1);
	int k = lg[r-l];
	return st[l][d][k] + st[r-(1<<k)][d][k];
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]);
	lg[0] = -1;
	rep(i, 1, n) lg[i] = lg[i>>1] + 1;
	rep(k, 0, 29) {
		if(!k) rep(i, 1, n-1) st[i][0][0] = Segment(min(a[i], a[i+1]), max(a[i], a[i+1]));
		else rep(i, 1, n-1) st[i][k][0] = query(k-1, st[i][k-1][0].l, st[i][k-1][0].r);
		rep(j, 1, 17) rep(i, 1, n-(1<<j)) st[i][k][j] = st[i][k][j-1] + st[i+(1<<(j-1))][k][j-1];
	}
	while(m--) {
		Segment now;
		scanf("%d%d", &now.l, &now.r);
		if(now.ok()) puts("0");
		else if(query(29, now.l, now.r).ok()) {
			int ans = 0;
			per(i, 29, 0) {
				if(!query(i, now.l, now.r).ok()) {
					now = query(i, now.l, now.r);
					ans |= 1 << i;
				}
			}
			printf("%d\n", ans+1);
		}
		else puts("-1");
	}
	return 0;
}