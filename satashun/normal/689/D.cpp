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

const int SZ = 1 << 18;

struct segtree_max {
    vector<int> dat;

    void init() {
	dat.resize(SZ * 2);
	rep(i, SZ * 2) dat[i] = INT_MIN;
    }

    void update(int pos, int x) {
	pos += SZ - 1;
	dat[pos] = x;

	while (pos > 0) {
	    pos = (pos - 1) / 2;
	    dat[pos] = max(dat[pos * 2 + 1], dat[pos * 2 + 2]);
	}
    }

    int get(int a, int b, int k = 0, int l = 0, int r = SZ) {
	if (b <= l || r <= a) return INT_MIN;
	if (a <= l && r <= b) return dat[k];
	return max(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
    }
} segM;

struct segtree_min {
    vector<int> dat;

    void init() {
	dat.resize(SZ * 2);
	rep(i, SZ * 2) dat[i] = INT_MAX;
    }

    void update(int pos, int x) {
	pos += SZ - 1;
	dat[pos] = x;

	while (pos > 0) {
	    pos = (pos - 1) / 2;
	    dat[pos] = min(dat[pos * 2 + 1], dat[pos * 2 + 2]);
	}
    }

    int get(int a, int b, int k = 0, int l = 0, int r = SZ) {
	if (b <= l || r <= a) return INT_MAX;
	if (a <= l && r <= b) return dat[k];
	return min(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
    }
} segm;

int n;
int a[200010];
int b[200010];
ll ret;

int main() {
    segM.init();
    segm.init();

    scanf("%d", &n);

    rep(i, n) {
	scanf("%d", &a[i]);
	segM.update(i, a[i]);
    }

    rep(i, n) {
	scanf("%d", &b[i]);
	segm.update(i, b[i]);
    }

    rep(i, n) {//[i, x)
	if (a[i] > b[i]) continue;

	int lo = i + 1, hi = n;

	if (segM.get(i, n) <= segm.get(i, n)) { 
	    lo = hi = n;
	}

	while (hi - lo > 1) {
	    int m = (lo + hi) / 2;
	    if (segM.get(i, m) <= segm.get(i, m)) lo = m;
	    else hi = m;
	}

	int lo2 = i + 1, hi2 = n;

	if (a[i] == b[i]) {
	    lo2 = hi2 = i;
	} else if (segM.get(i, n) < segm.get(i, n)) {
	    lo2 = hi2 = n;
	}

	while (hi2 - lo2 > 1) {
	    int m = (lo2 + hi2) / 2;
	    if (segM.get(i, m) < segm.get(i, m)) lo2 = m;
	    else hi2 = m;
	}
/*
	cout << "max=" << segM.get(i, lo) << " " << segM.get(i, hi) << endl;
	cout << "min=" << segm.get(i, lo) << " " << segm.get(i, hi) << endl;
	cout << "max=" << segM.get(i, lo2) << " " << segM.get(i, hi2) << endl;
	cout << "min=" << segm.get(i, lo2) << " " << segm.get(i, hi2) << endl;
	
	cout << lo << " " << lo2 << endl;
*/	
	ret += lo - lo2;
    }
    cout << ret << endl;

    return 0;
}