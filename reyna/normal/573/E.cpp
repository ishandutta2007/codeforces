//In the name of God

// Waiting for the rain T_T

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define int long long

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }


int pw(int a, int b, int mod) { return (b? pw(1LL * a * a % mod, b >> 1, mod) * 1LL * (b & 1? a : 1) % mod: 1); }


const int maxN = 1e5 + 49;
const int SQ = 349;
const int mod = 0;
const int base = 1000 * 1000 + 3;
const int oo = 1e18 + 49;

inline int read() { int x; cin >> x; return x; }

int n, lh[maxN], h[SQ], t[SQ], s[SQ][SQ], mark[maxN], val[maxN], bad[maxN], addh[SQ], addt[SQ];
pii a[maxN], mx;

int geth(int i) { return addh[i / SQ] + lh[i]; }
int getm(int i) { return val[i]; }
int getval(int i) { if (i == -1) return -oo; return val[i] * addt[i / SQ] + addh[i / SQ] + lh[i]; };

int when(int i, int j) {
	if (i > j) return when(j, i);
	return (geth(i) - geth(j) + getm(j) - getm(i) - 1) / (getm(j) - getm(i));
}
vector<int> st;

void apply() {
	for (int i : st) if (!mark[a[i].y] && make_pair(geth(a[i].y), a[i].y) < mx) {
//		cout << " hi " << i << '\n';
		bad[i] = 1;
	} //else cout << "hello\n";
	st.clear();
}

void build(int ind) {
	int b = ind * SQ, e = min(n, b + SQ);
	mx = {-oo, -oo};
	for (int i = b; i < e; ++ i)
		bad[i] = 0;
	h[ind] = 0;
	int &p = (t[ind] = 0), last = -oo;
	for (int i = e - 1; i > b - 1; -- i) if (!mark[a[i].y]) {
		if (last != a[i].x) {
//			cout << "^" << a[i].x << ' ';
			apply();
			
		}
		smax(mx, make_pair(geth(a[i].y), a[i].y));
		st.push_back(i);
		last = a[i].x;
	}
	apply();
	for (int i = b; i < e; ++ i) if (!mark[a[i].y] && !bad[i]) {
//		cout << "hi " << a[i].y << ' ' << p << endl;
		while (p > 1 && when(s[ind][p - 1], s[ind][p - 2]) >= when(s[ind][p - 1], a[i].y))
			-- p;
		s[ind][p++] = a[i].y;
	}
}


int get(int ind, int tcur) {
	int &bg = h[ind], &ed = t[ind];
	if (bg == ed) return -1;
	while (bg < ed - 1 && when(s[ind][bg], s[ind][bg + 1]) <= tcur)
		++ bg;
	return s[ind][bg];
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read();
	for (int i = 0; i < n; i++)
		val[i] = a[i].x = read(), a[i].y = i;
	for (int i = 0; i * SQ < n; i++)
		addt[i]++, sort(a + i * SQ, a + min((i + 1) * SQ, n)), build(i);
	int res = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		int best = -oo, id = -1;
		for (int j = 0; j * SQ < n; j++) {
			int x = get(j, addt[j]);
			if (getval(x) > best)
				id = x, best = getval(x);	
		}
		int group = id / SQ;
		int b = group * SQ, e = min(group * SQ + SQ, n);
		mark[id] = 1;
		int x = id;
		for (int i = b; i < e; i++) if (!mark[a[i].y]) {
			if (a[i].y > x)
				lh[a[i].y] += a[i].x;
			else
				lh[a[i].y] += val[x];
		}
//		cout << i << ' ' << x << ' ' << best<< '\n';
		build(group);
		for (int i = 0; i < group; i++)
			addh[i] += val[x];
		for (int i = group + 1; i * SQ < n; i++)
			addt[i] ++;
		sum += best;
		smax(res, sum);
	}
	cout << res << '\n';
}