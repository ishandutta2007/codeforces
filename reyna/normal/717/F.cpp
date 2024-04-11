#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define x first
#define y second
#define tysiac 1010
#define milion 1000100
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define OUT(x) { cout << x; return 0; }
#define PRINT(x, y) {printf("%d %d\n", x, y); return;} 
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
typedef pair <double, int> PDI;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int T, n, m, K, a, b, c, k, d, g, Q, DL;
const int N = (1 << 18);
const long long inf = 1e18;
struct segtree {
    long long mn[N * 4 + 5], ch[N * 4 + 5];
    void build(int v = 1, int b = 0, int e = N) {
        mn[v] = 0;
        ch[v] = 0;
        if (b + 1 == e) {
            return;
        }
        int m = b + e >> 1, l = v << 1, r = l | 1;
        build(l, b, m);
        build(r, m, e);
    }
    segtree() {
        build();
    }
    void push(int v, int l, int r) {
        ch[l] += ch[v];
        ch[r] += ch[v];
        mn[l] += ch[v];
        mn[r] += ch[v];
        ch[v] = 0;
    }
    void update0(int i, int j, long long x, int v = 1, int b = 0, int e = N) {
        if (i >= e || b >= j)
            return;
        if (i <= b && e <= j) {
            mn[v] += x;
            ch[v] += x;
            return;
        }
        int m = b + e >> 1, l = v << 1, r = l | 1;
        push(v, l, r);
        update0(i, j, x, l, b, m);
        update0(i, j, x, r, m, e);
        mn[v] = min(mn[l], mn[r]);
    }
    long long query0(int i, int j, int v = 1, int b = 0, int e = N) {
        if (i >= e || b >= j)
            return inf;
        if (i <= b && e <= j)
            return mn[v];
        int m = b + e >> 1, l = v << 1, r = l | 1;
        push(v, l, r);
        return min(query0(i, j, l, b, m), query0(i, j, r, m, e));
    }
    long long query(int i, int j, int v = 1, int b = 0, int e = N) { return query0(i, j + 1, v, b, e); }
    void update(int i, int j, int x, int v = 1, int b = 0, int e = N) { update0(i, j + 1, x, v, b, e); }
};


segtree parzyste, nieparzyste;
#define maxn 500100
ll t[maxn], roz[maxn];

inline int numer(int x) {
	return (x + 1) >> 1;
}


PII getCorrectBounds(int a, int b, int type) {
	int n1 = numer(a), n2 = numer(b);
	if (type == 1 && a % 2 == 0) n1++;
	if (type == 0 && b % 2 == 1) n2--;
	return mp(n1, n2);
}

inline ll getQuery(int a, int b, int type) {
	PII bnd = getCorrectBounds(a, b, type);
	if (type) return nieparzyste.query(bnd.e1, bnd.e2);
	return parzyste.query(bnd.e1, bnd.e2);
}

inline void setUpdate(int a, int b, int value, int type) {
	PII bnd = getCorrectBounds(a, b, type);
	if (type) nieparzyste.update(bnd.e1, bnd.e2, value);
	else parzyste.update(bnd.e1, bnd.e2, value);
}

inline void correct(int x, int y, ll value) {
	int dl = y - x + 1;
	if (x % 2) setUpdate(x, y, value, 1);
	else setUpdate(x, y, value, 0);
	if (dl & 1) {
		if (y == n) return;
		if ((y + 1) % 2 == 1) {
			setUpdate(y+1, n, value, 0);
			setUpdate(y+1, n, -value, 1);
		}
		else {
			setUpdate(y+1, n, -value, 0);
			setUpdate(y+1, n, value, 1);
		}
	}
}

inline bool answer(int a, int b) {
	correct(a, b, -1);
	bool ans = 1;
	ll before = 0;
	if (a > 1) {
		a--;
		if (a & 1) before = getQuery(a, a, 1);
		else before = getQuery(a, a, 0);
		a++;
		correct(a - 2, a - 2, before);
	}
	
	ll sumAll = 0;
	if (b & 1) sumAll = getQuery(b, b, 1);
	else sumAll = getQuery(b, b, 0);
	//cout << " Sum : " << sumAll << endl;
	if (sumAll != 0) ans = 0;
	
	if (a != b) {
		ll pp = getQuery(a, b, 0);
		ll np = getQuery(a, b, 1);
		if (pp < 0 || np < 0) ans = 0;
	}
	
	if (a > 1) correct(a - 2, a - 2, -before);
	correct(a, b, 1);
	return ans;
}

int main() {
	boost;
	cin >> n;
	FOR(i, 1, n) {
		cin >> t[i];
		roz[i] = t[i] - roz[i-1];
		if (i % 2 == 0) parzyste.update(numer(i), numer(i), roz[i]);
		else nieparzyste.update(numer(i), numer(i), roz[i]);
	}
	  
	int q;
	cin >> q;
	while (q--) {
		int type, value;
		cin >> type;
		if (type == 1) {
			cin >> a >> b >> value;
			++a; ++b;
			correct(a, b, value);
		}
		else {
			cin >> a >> b;
			++a; ++b;
			cout << answer(a, b) << "\n";
		}
	}
	
	
}