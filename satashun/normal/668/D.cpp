#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

// 1-indexed, [1, n]
template<class T>
class BIT {
    vector<T> bit;
    int n;

    public:
    void init(int N) {
	n = N + 1;
	bit = vector<T>(N + 2, 0);
    }

    inline T sum(int i) {
	++i;
	T s = 0;

	while (i > 0) {
	    s += bit[i];
	    i -= i & -i;
	}

	return s;
    }

    inline void add(int i, T x) {
	++i;
	while (i <= n) {
	    bit[i] += x;
	    i += i & -i;
	}
    }
};

int n;
vi xs;
int tp[1000010];
int t[1000010];
int x[1000010];
vi pos[1000010];
BIT<int> T[1000010];

int main() {
    scanf("%d", &n);
    xs.resize(n);

    rep(i, n) {
	scanf("%d %d %d", &tp[i], &t[i], &x[i]);
	xs[i] = x[i];
    }

    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());

    rep(i, n) {
	x[i] = lower_bound(ALL(xs), x[i]) - xs.begin();	
    }

    rep(i, n) {
	pos[x[i]].pb(t[i]);
    }

    rep(i, xs.size()) {
	sort(ALL(pos[i]));

	T[i].init(pos[i].size() + 2);
    }

    rep(i, n) {
	//cout << tp[i] << " " << t[i] << " " << x[i] << endl;
	int p = lower_bound(ALL(pos[x[i]]), t[i]) - pos[x[i]].begin();
	//cout << "p::: " << p << endl;
	
	if (tp[i] == 1) {
	    T[x[i]].add(p, 1);
	} else if (tp[i] == 2) {
	    T[x[i]].add(p, -1);
	} else {
	    int res = T[x[i]].sum(p);
	    printf("%d\n", res);
	}
    }

    return 0;
}