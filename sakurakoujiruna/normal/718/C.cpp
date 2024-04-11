#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll Mod = (ll)1e9 + 7;

struct Mat {
	int n, m;
	int num[2][2];
	Mat() {}
	Mat(int n, int m) : n(n), m(m) {
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				num[i][j] = 0;
	}
	Mat operator +(Mat mat) const {
		Mat ret(n, m);
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				ret.num[i][j] = (num[i][j] + mat.num[i][j]) % Mod;
		return ret;
	}
	Mat operator *(Mat mat) const {
		Mat ret(n, mat.m);
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < mat.m; j ++) {
				ret.num[i][j] = 0;
				for(int k = 0; k < m; k ++) {
					ret.num[i][j] += (ll)num[i][k] * mat.num[k][j] % Mod;
					ret.num[i][j] %= Mod;
				}
			}
		return ret;
	}
};

Mat e, f;

Mat qpow(Mat a, int b) {
	Mat tmp = a;
	Mat ret = e;
	for(; b > 0; b >>= 1) {
		if(b & 1)
			ret = ret * tmp;
		tmp = tmp * tmp;
	}
	return ret;
}
const int N = 100011;
int a[N];
struct SegTree {
	int l[N << 2], r[N << 2];
	Mat mat[N << 2];
	Mat flag[N << 2];
	void push(int x) {
		mat[x] = flag[x] * mat[x];
		if(l[x] + 1 != r[x]) {
			flag[2 * x] = flag[2 * x] * flag[x];
			flag[2 * x + 1] = flag[2 * x + 1] * flag[x];
		}
		flag[x] = e;
	}
	void init(int left, int right, int x = 1) {
		l[x] = left; r[x] = right; flag[x] = e;
		mat[x] = qpow(f, a[left]);
		if(left + 1 != right) {
			int mid = (left + right) / 2;
			init(left, mid, 2 * x);
			init(mid, right, 2 * x + 1);
			mat[x] = mat[2 * x] + mat[2 * x + 1];
		}
	}
	void change(int left, int right, Mat c, int x = 1) {
		push(x);
		if(left == l[x] && right == r[x]) {
			flag[x] = c;
			push(x);
		} else {
			int mid = (l[x] + r[x]) / 2;
			if(right <= mid) {
				push(2 * x + 1);
				change(left, right, c, 2 * x);
			} else if(left >= mid) {
				push(2 * x);
				change(left, right, c, 2 * x + 1);
			} else {
				change(left, mid, c, 2 * x);
				change(mid, right, c, 2 * x + 1);
			}
			mat[x] = mat[2 * x] + mat[2 * x + 1];
		}
	}
	Mat query(int left, int right, int x = 1) {
		push(x);
		if(l[x] == left && r[x] == right)
			return mat[x];
		int mid = (l[x] + r[x]) / 2;
		if(right <= mid)
			return query(left, right, 2 * x);
		else if(left >= mid)
			return query(left, right, 2 * x + 1);
		else
			return query(left, mid, 2 * x) + query(mid, right, 2 * x + 1);
	}
}st;

int main() {
	ios :: sync_with_stdio(false);

	e.n = e.m = 2;
	e.num[0][0] = e.num[1][1] = 1;
	e.num[0][1] = e.num[1][0] = 0;
	f.n = f.m = 2;
	f.num[0][0] = 0;
	f.num[0][1] = f.num[1][0] = f.num[1][1] = 1;

	//cout << qpow(f, 2).num[0][1] << '\n';

	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	st.init(1, n + 1);
	while(m --) {
		int t;
		cin >> t;
		if(t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			st.change(l, r + 1, qpow(f, x));
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << st.query(l, r + 1).num[0][1] << '\n';
			/*
			for(int i = l; i <= r; i ++)
				cout << st.query(i, i + 1).num[0][1] << ' ';
			cout << '\n';
			*/
		}
	}
	return 0;
}