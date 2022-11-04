#include<bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
using LL = long long;
using PI = pair<int, int>;
using VI = vector<int>;
#define endl '\n'
const int N = 1000005;

struct node {
	LL sum, ls, rs, val;
}P[N], O;

vector<int> q[20];

struct WinnerTree {
	vector<node> v[N * 4];
	int n;
	
	node calc(node A, node B) {
		LL sum = max(A.sum, B.sum);
		chkmax(sum, A.ls + B.rs);// chkmax(sum, A.rs + B.ls)
		O.sum = sum; 
		O.ls = B.ls, O.rs = A.rs, O.val = A.val + B.val;
		chkmax(O.ls, B.val + A.ls); //O.ls = A.val + B.ls
		chkmax(O.rs, A.val + B.rs); //O.rs = B.val + A.ls
		return O;
	}
	
	void build(int an) {
		n = an;
		for (int i = n; i < 2 * n; i ++) {
			v[i][0] = P[i - n];
		}
		for (int i = n - 1; i > 0; i --) {
			int vn = v[i].size();
			for (int j = 0; j < vn / 2; j ++) {
				v[i][j] = calc(v[i * 2][j], v[i * 2 + 1][j]);
				v[i][j + vn / 2] = calc(v[i * 2 + 1][j], v[i * 2][j]);
			}
		}
	}
	
	inline void init(int u, int d) {
		v[u].resize(1 << d);
		if (d == 0) return;
		init(u * 2, d - 1);
		init(u * 2 + 1, d - 1);
	}
	
}WT;

LL a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int m; cin >> m;
	int n = (1 << m);
	WT.init(1, m);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		O.val = a[i];
		if (a[i] > 0) {
			O.sum = O.ls = O.rs = a[i];
		} else {
			O.sum = O.ls = O.rs = 0;
		}
		P[i] = O;
//		cerr << P[i].sum << ' ' << P[i].ls << ' ' << P[i].rs << endl;
	}
	WT.build(n);
	int q; cin >> q;
	int st = 0;
	while (q --) {
		int k; cin >> k;
		st ^= (1 << k);
		cout << WT.v[1][st].sum << endl;
	}
	return 0;
}