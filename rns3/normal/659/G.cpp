#include <stdio.h>
#include <algorithm>
using namespace std;
#define mod 1000000007

typedef pair<int, int> pi;
#define N 4010000

int Mx[N], pos[N], a[N];

void build(int st, int en, int id) {
	if(st == en) {
		Mx[id] = a[st];
		pos[id] = st;
		return ;
	}
	int mid = (st + en) >> 1;
	build(st, mid, id * 2);
	build(mid + 1, en, id * 2 + 1);
	Mx[id] = Mx[id * 2];
	pos[id] = pos[id * 2];
	if(Mx[id * 2 + 1] > Mx[id]) Mx[id] = Mx[id * 2 + 1], pos[id] = pos[id * 2 + 1];
	return ;
}

pi Calc(int l, int r, int st, int en, int id) {
	if(l > en || r < st) return pi(0, 0);
	if(l <= st && en <= r) return pi(Mx[id], pos[id]);
	int mid = (st + en) >> 1;
	pi a = Calc(l, r, st, mid, id * 2);
	pi b = Calc(l, r, mid + 1, en, id * 2 + 1);
	pi c = a;
	if(c.first < b.first) c = b;
	return c;
}

int n;

struct dat{
	int ans, lans, rans, allans;
	dat(int ans = 0, int lans = 0, int rans = 0, int allans = 0):ans(ans), lans(lans), rans(rans), allans(allans){}
};

void Mod(int &a) {
	if(a >= mod) a -= mod;
	return ;
}
dat calc(int st, int en) {
	if(st == en) return dat(a[st] - 1, a[st] - 1, a[st] - 1, a[st] - 1);
	int mx = 0;
	pi A = Calc(st, en, 0, n - 1, 1);
	int x = A.second;
	if(x == st) {
		dat aa = calc(st + 1, en);
		int lans = a[st] - 1 + 1ll * (a[st + 1] - 1) * aa.lans % mod;
		Mod(lans);
		int allans = 1ll * aa.allans * (a[st + 1] - 1) % mod;
		int rans = aa.rans + allans;
		Mod(rans);
		int ans = aa.ans + lans;
		Mod(ans);
		return dat(ans, lans, rans, allans);
	} else if(x == en) {
		dat aa = calc(st, en - 1);
		int rans = a[en] - 1 + 1ll * (a[en - 1] - 1) * aa.rans % mod;
		Mod(rans);
		int allans = 1ll * aa.allans * (a[en - 1] - 1) % mod;
		int lans = aa.lans + allans;
		Mod(lans);
		int ans = aa.ans + rans;
		Mod(ans);
		return dat(ans, lans, rans, allans);
	}
	dat aa = calc(st, x - 1);
	dat bb = calc(x + 1, en);
	int k = min(a[x - 1] - 1, a[x + 1] - 1);
	int lans = aa.lans + 1ll * aa.allans * (a[x - 1] - 1) %mod;
	Mod(lans);
	lans += 1ll * aa.allans * bb.lans % mod * k % mod;
	Mod(lans);
	int rans = bb.rans + 1ll * bb.allans * (a[x + 1] - 1) % mod;
	Mod(rans);
	rans += 1ll * bb.allans * aa.rans % mod * k % mod;
	Mod(rans);
	int allans = 1ll * aa.allans * bb.allans % mod * k % mod;
	int ans = aa.ans + bb.ans;
	Mod(ans);
	ans += a[x] - 1;
	Mod(ans);
	ans += 1ll * (a[x - 1] - 1) * aa.rans % mod;
	Mod(ans);
	ans += 1ll * (a[x + 1] - 1) * bb.lans % mod;
	Mod(ans);
	ans += 1ll * k * aa.rans % mod * bb.lans % mod;
	Mod(ans);
	return dat(ans, lans, rans, allans);
}

int main() {
	//freopen("G.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
	build(0, n-1, 1);
	int ans = calc(0, n - 1).ans;
	printf("%d\n", ans);
	return 0;
}