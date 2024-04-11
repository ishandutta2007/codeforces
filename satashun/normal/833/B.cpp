#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

int sz;
const int INF = TEN(9);

struct starry_sky_tree {
    int all[1<<17], ma[1<<17];

    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        rep(i, sz * 2) {
            all[i] = 0;
            ma[i] = 0;
        }
    }

    void add(int a, int b, int x, int k, int l, int r) {
        if (b <= l || r <= a) return ;
        if (a <= l && r <= b) {
            all[k] += x; return ; 
        }

        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        ma[k] = max(ma[k * 2 + 1] + all[k * 2 + 1], ma[k * 2 + 2] + all[k * 2 + 2]);  
    }

    int get(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) {
            return ma[k] + all[k];
        }

        int lc = get(a, b, k * 2 + 1, l, (l + r) / 2);
        int rc = get(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(lc, rc) + all[k];
    }
} seg;

const int maxn = 35010;

int dp[60][maxn];
int la[maxn], pre[maxn];

int main() {
	int n, k; cin >> n >> k;
	V<int> a(n);
	memset(la, -1, sizeof(la));

	rep(i, n) {
		cin >> a[i];
		--a[i];
		pre[i] = la[a[i]];
		la[a[i]] = i;
	}

	dp[0][0] = 0;
	rep(i, n) dp[0][i+1] = -INF;

	rep(i, k) {
		seg.init(n);
		rep(j, n) {
			seg.add(j, j+1, dp[i][j], 0, 0, sz);
			seg.add(pre[j]+1, j+1, 1, 0, 0, sz);
			int v = seg.get(0, j+1, 0, 0, sz);
			if (v >= 0) {
				dp[i+1][j+1] = v;
			}
		}
	}

	cout << dp[k][n] << endl;

	return 0;
}