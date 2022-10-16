// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, m, k;

vector<PII> get(vector<int> e) {
	vector<PII> a;
	for (int v: e) {
		int w = v, z = 1;
		while (w % m == 0) w /= m, z *= m;
		a.pb(mp(w, z));
	}
	vector<PII> b;
	for (PII x: a) {
		if (b.size() && b.back().fi == x.fi) b.back().se += x.se;
		else b.pb(x);
	}
	return b;
}

signed main() {
    int T; read(T);
    while (T--) {
    	read(n), read(m);
    	vector<int> a, b;
    	for (int i = 1; i <= n; i++) {
    		int v; read(v);
    		a.pb(v);
    	}
    	read(k);
    	for (int i = 1; i <= k; i++) {
    		int v; read(v);
    		b.pb(v);
    	}
    	puts(get(a) == get(b) ? "Yes" : "No");
    }
    return 0;
}