#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct Segment {
	int l, r, id;
	Segment(int l = -Inf, int r = Inf, int id = 0) : l(l), r(r), id(id) { }
	bool operator < (const Segment &s) const {
		return mak(l, r) < mak(s.l, s.r);
	}
};

struct State {
	bool p, s;
	char mode;
	int f1, f2;
	State() : f1(-1), f2(-1) { }
	State(bool p, bool s, char mode, int f1 = -1, int f2 = -1) : p(p), s(s), mode(mode), f1(f1), f2(f2) { }
};

bool inline upd(int &a, int b) {
	if (a < b) return (a = b), 1;
	else return 0;
}

State ss[27000000];
int sis;

void inline getsid(int &id, const State &s) {
	assert(s.f1);
	if (!~id) ss[id = ++sis] = s;
	else ss[id] = s;
	assert(ss[id].f1);
}

int l[2005], r[2005];
int dp[2005][2005][2][2], tmp[2][4005][2][2];
int fr[2005][2005][2][2], tfr[2][4005][2][2];
int n;
vector<Segment> seg;
vector<int> nei[2005];
int siz[2005];

void dfs(int now) {
	if (!SZ(nei[now])) {
		siz[now] = 1;
		dp[now][0][0][0] = r[now] - l[now];
		getsid(fr[now][0][0][0], State(0, 0, 1));
		return;
	}
	parse(to, nei[now]) dfs(to);
	memset(tmp, -Inf, sizeof(tmp));
	memset(tfr, -1, sizeof(tfr));
	siz[now] = SZ(nei[now]) + 1;
	int ths = 1, lst = 0;
	tmp[0][0][0][0] = 0;
	getsid(tfr[0][0][0][0], State());
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		int lp = i ? r[nei[now][i - 1]] : l[now], rp = l[to], len = rp - lp;
		loop(k, siz[now] + 1) loop(nk, siz[to] + 1) if (k + nk <= n) {
			loop(p, 2) loop(s, 2) loop(np, 2) loop(ns, 2) {
				int pre = tmp[lst][k][p][s], cur = dp[to][nk][np][ns];
				int prf = tfr[lst][k][p][s], cuf = fr[to][nk][np][ns];
				if (upd(tmp[ths][k + nk][p][ns], pre + cur)) {
					getsid(tfr[ths][k + nk][p][ns], State(p, ns, 0, prf, cuf));
				}
				int kk = k + nk + 1 - s - np, pp = i ? p : 1;
				if (kk >= 0 && upd(tmp[ths][kk][pp][ns], pre + len + cur)) {
					getsid(tfr[ths][kk][pp][ns], State(pp, ns, 1, prf, cuf));
				}
			}
		}
		siz[now] += siz[to]; siz[now] = min(siz[now], n);
		swap(ths, lst);
		memset(tmp[ths], -Inf, sizeof(tmp[ths]));
		memset(tfr[ths], -1, sizeof(tfr[ths]));
	}
	int lp = r[nei[now].back()], rp = r[now], len = rp - lp;
	loop(k, siz[now] + 1) loop(p, 2) loop(s, 2) {
		int pre = tmp[lst][k][p][s], prf = tfr[lst][k][p][s];
		if (upd(tmp[ths][k][p][0], pre)) {
			getsid(tfr[ths][k][p][0], State(p, 0, 0, prf));
		}
		int kk = k + 1 - s;
		if (kk >= 0 && upd(tmp[ths][kk][p][1], pre + len)) {
			getsid(tfr[ths][kk][p][1], State(p, 1, 1, prf));
		}
	}
	loop(k, siz[now]) loop(p, 2) loop(s, 2) {
		if (upd(dp[now][k][p][s], tmp[ths][k + 1][p][s])) {
			fr[now][k][p][s] = tfr[ths][k + 1][p][s];
		}
		loop(np, p + 1) loop(ns, s + 1) {
			if (upd(dp[now][k][np][ns], dp[now][k][p][s])) {
				getsid(fr[now][k][np][ns], State(np, ns, 2, fr[now][k][p][s]));
			}
		}
	}
	dp[now][0][0][1] = dp[now][0][1][0] = dp[now][0][1][1] = dp[now][1][1][1] = -Inf;
	fr[now][0][0][1] = fr[now][0][1][0] = fr[now][0][1][1] = fr[now][1][1][1] = -1;
}

struct Piece {
	int l, r;
	bool cl, cr;
	Piece(int l = -1, int r = -1, int cl = 0, int cr = 0) : l(l), r(r), cl(cl), cr(cr) { }
};

vector<Piece> pcs;
vector<Segment> segs;

void dft(int now, int i, int sid) {
	if (i < 0) return;
	const State &st = ss[sid];
	int s1 = st.f1, s2 = st.f2, mode = st.mode;
	int lp, rp, f1 = ~s1 && !~ss[s1].f1 ? st.p : 0, f2 = st.s;
	if (!SZ(nei[now])) {
		lp = l[now], rp = r[now];
	} else if (!i) {
		lp = l[now], rp = l[nei[now][0]];
	} else if (i == SZ(nei[now])) {
		lp = r[nei[now].back()], rp = r[now];
	} else {
		lp = r[nei[now][i - 1]], rp = l[nei[now][i]];
	}
	if (~s1) dft(now, i - (mode != 2), s1);
	if (mode == 1) pcs.emb(lp, rp, f1, f2);
	if (mode == 2) pcs.back().cl &= f1, pcs.back().cr &= f2;
	if (~s2) dft(nei[now][i], SZ(nei[nei[now][i]]), s2);
}

Segment sel[2005];

void dfu(int now) {
	parse(to, nei[now]) dfu(to);
	loop(i, SZ(segs)) if (segs[i].l >= l[now] && segs[i].r <= r[now]) {
		sel[now] = segs[i];
		segs.erase(segs.begin() + i);
		break;
	}
}

int main() {
	scanf("%d", &n);
	seg.emb();
	cont(i, n) {
		scanf("%d%d", l + i, r + i);
		seg.emb(l[i], r[i], i);
	}
	sort(all(seg));
	vector<pair<int, int> > stk;
	stk.emb(Inf, 0);
	cont(i, n) {
		while (stk.back().first < seg[i].l) stk.pob();
		nei[stk.back().second].pub(seg[i].id);
		stk.emb(seg[i].r, seg[i].id);
	}
	memset(dp, -Inf, sizeof(dp));
	memset(fr, -1, sizeof(fr));
	int ans = 0;
	parse(bg, nei[0]) {
		dfs(bg);
		pcs.clear(); segs.clear();
		ans += dp[bg][0][0][0];
		dft(bg, SZ(nei[bg]), fr[bg][0][0][0]);
		loop(i, SZ(pcs)) {
			int lp = pcs[i].l, rp = pcs[i].r;
			if (SZ(segs) && segs.back().r == lp && pcs[i].cl) segs.back().r = rp;
			else if (SZ(segs) && i && pcs[i - 1].cr) segs.back().r = rp;
			else segs.emb(lp, rp);
		}
		dfu(bg);
	}
	printf("%d\n", ans);
	cont(i, n) printf("%d %d\n", sel[i].l, sel[i].r);
	return 0;
}