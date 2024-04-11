#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1000000007;

typedef array<array<ll,2>,2> Ar;

struct Mat {
	array<array<ll,2>,2> a;
	Mat() {
		a[0][0] = a[1][0] = a[0][1] = a[1][1] = -200;
	}
	Mat(const array<array<ll,2>,2>& a) : a(a) {}
};
Mat operator*(const Mat& a, const Mat& b) {
	Mat r;
	r.a[0][0] = (a.a[0][0] * b.a[0][0] + a.a[0][1] * b.a[1][0]) % mod;
	r.a[1][0] = (a.a[1][0] * b.a[0][0] + a.a[1][1] * b.a[1][0]) % mod;
	r.a[0][1] = (a.a[0][0] * b.a[0][1] + a.a[0][1] * b.a[1][1]) % mod;
	r.a[1][1] = (a.a[1][0] * b.a[0][1] + a.a[1][1] * b.a[1][1]) % mod;
	return r;
}
Mat operator+(const Mat& a, const Mat& b) {
	Mat r;
	rep(i,0,2) rep(j,0,2) r.a[i][j] = (a.a[i][j] + b.a[i][j]) % mod;
	return r;
}
void operator*=(Mat& a, const Mat& b) { a = a * b; }
void operator+=(Mat& a, const Mat& b) { a = a + b; }
bool operator!=(const Mat& a, const Mat& b) {
	rep(i,0,2) rep(j,0,2) if (a.a[i][j] != b.a[i][j]) return true;
	return false;
}
Mat ID = {{{{1,0},{0,1}}}};
Mat ZERO = {{{{0,0},{0,0}}}};
Mat FIB = {{{{1,1},{1,0}}}};

Mat matpow(Mat a, ll e) {
	if (e == 0) return ID;
	Mat x = matpow(a * a, e >> 1);
	if (e & 1) x = x * a;
	return x;
}

struct LazySegmentTree {
	typedef Mat T; typedef vector<T> vt;
	int N;
	vt leaf, upd;
	LazySegmentTree(vt& li) : N(sz(li)), leaf(4*N), upd(4*N) {
		build(1,0,N-1,li);
	}
	void build(int cur, int a, int b, vt& li) {
		if (a == b)
			leaf[cur] = li[a];
		else {
			int mid = (a+b)/2;
			build(2 * cur, a, mid, li);
			build(2 * cur + 1, mid+1, b, li);
			leaf[cur] = leaf[2*cur] + leaf[2*cur+1];
		}
		upd[cur] = ID;
	}
	void update(int a, int b, T val) { // add val to [a,b)
		assert(0 <= a && a <= b && b <= N);
		update(1,0,N-1,a,b-1,val);
	}
	void update(int cur, int L, int R, int a, int b, T val) {
		if(a <= L && R <= b) {
			upd[cur] *= val;
			leaf[cur] *= val;
		}
		else {
			push(cur);
			int mid = (L+R)/2;
			if (mid >= a && L <= b)
				update(2*cur, L, mid, a, b, val);
			if (R >= a && mid+1 <= b)
				update(2*cur+1, mid+1, R, a, b, val);
			leaf[cur] = leaf[2*cur] + leaf[2*cur+1];
		}
	}
	T query(int a, int b) { // compute sum of values in [a,b)
		assert(0 <= a && a <= b && b <= N);
		return query(1,0,N-1,a,b-1);
	}
	T query(int cur, int L, int R, int a, int b) {
		if (a <= L && R <= b)
			return leaf[cur];
		push(cur);
		int mid = (L+R)/2;
		T ret = ZERO;
		if (mid >= a && L <= b)
			ret += query(2*cur, L, mid, a, b);
		if (R >= a && mid+1 <= b)
			ret += query(2*cur+1, mid+1, R, a, b);
		return ret;
	}
	void push(int cur) {
		if (upd[cur] != ID) {
			if (cur < 2*N) {
				upd[2*cur] *= upd[cur];
				upd[2*cur+1] *= upd[cur];
				leaf[2*cur] *= upd[cur];
				leaf[2*cur+1] *= upd[cur];
			}
			upd[cur] = ID;
		}
	}
};

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin.exceptions(cin.failbit | cin.eofbit | cin.badbit);

// Mat m = matpow(FIB, 2) * FIB;
// rep(i,0,2) rep(j,0,2) cout << m.a[i][j] << ' '; cout << endl;

	int N, M;
	cin >> N >> M;
	vector<Mat> li(N);
	rep(i,0,N) {
		int x;
		cin >> x;
		li[i] = matpow(FIB, x);
	}

	LazySegmentTree st(li);
	rep(qi,0,M) {
		int type, l, r;
		cin >> type >> l >> r;
		--l;
		if (type == 1) {
			int x;
			cin >> x;
			Mat m = matpow(FIB, x);
			st.update(l,r,m);
		}
		else {
			Mat m = st.query(l,r);
			// rep(i,0,2) rep(j,0,2) cout << m.a[i][j] << ' '; cout << endl;
			cout << m.a[0][1] << '\n';
		}
	}
	exit(0);
}