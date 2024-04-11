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

const int N = 200010;

// 1-indexed, [1, n]
template<class T>
class BIT {
    T bit[N];
    int n;

    public:
    BIT() {
	n = N;
	memset(bit, 0, sizeof(bit));
    }

    T sum(int i) {
	T s = 0;
	++i;

	while (i > 0) {
	    s += bit[i];
	    i -= i & -i;
	}
	return s;
    }

    void add(int i, T x) {
	++i;

	while (i <= n) {
	    bit[i] += x;
	    i += i & -i;
	}
    }
};

int n, k, a, b, q;
BIT<int> T1, T2;
int num[200010];

int main() {
    cin >> n >> k >> a >> b >> q;

    while (q--) {
	int tp;
	cin >> tp;
	if (tp == 1) {
	    int d, ad;
	    cin >> d >> ad;
	    int nw = min(max(b - num[d], 0), ad);
	    T1.add(d    , nw);

	    nw = min(max(a - num[d], 0), ad);
	    T2.add(n + 1 - d, nw);
	    num[d] += ad;
	} else {
	    int p;
	    cin >> p;
	    int ret = T1.sum(p - 1) + T2.sum(max(n + 1 - p - k, 0));
	    cout << ret << "\n";
	}
    }
    return 0;
}