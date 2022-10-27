#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int sum[N<<2], tag[N<<2];

void init(int n) {
	for (int i = 1; i <= n<<2; i ++) {
		sum[i] = 0, tag[i] = -1;
	}
}
void pushdown(int l, int r, int rt) {
	if (tag[rt] != -1) {
		tag[rt<<1] = tag[rt];
		tag[rt<<1|1] = tag[rt];
		int mid = (l+r)>>1;
		sum[rt<<1] = (mid - l + 1) * tag[rt];
		sum[rt<<1|1] = (r - mid) * tag[rt];
		tag[rt] = -1;
	}
}

void update(int l, int r, int rt, int L, int R, int x) {
	if (L <= l && r <= R) {
		sum[rt] = (r - l + 1) * x;
		tag[rt] = x;
		return;
	}
	int mid = (l + r) >> 1; pushdown(l, r, rt);
	if (L <= mid) update(l, mid, rt<<1, L, R, x);
	if (R  > mid) update(mid+1, r, rt<<1|1, L, R, x);
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
int query(int l, int r, int rt, int L, int R) {
	if (L <= l && r <= R) return sum[rt];
	int mid = (l + r) >> 1; pushdown(l, r, rt);
	int ans = 0;
	if (L <= mid) ans += query(l, mid, rt<<1, L, R);
	if (R  > mid) ans += query(mid+1, r, rt<<1|1, L, R);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t --) {
		int n, q;
		cin >> n >> q;
		
		string s, f; 
		cin >> s >> f;

		vector<int> l(q), r(q);
		for (int i = 0; i < q; i ++) {
			cin >> l[i] >> r[i];
			l[i] --, r[i] --;
		}

		init(n);
		for (int i = 0; i < n; i ++) {
			if (f[i] == '1') update(0,n-1,1,i,i,1);
		}
		bool gg = false;
		for (int i = q - 1; i >= 0; i --) {
			int s = query(0,n-1,1,l[i],r[i]);
			int len = r[i] - l[i] + 1;
			if (2 * s == len) {
				gg = true; break;
			} else if (2 * s < len) {
				update(0,n-1,1,l[i],r[i],0);
			} else {
				update(0,n-1,1,l[i],r[i],1);
			}
		}

		for (int i = 0; i < n; i ++) {
			if (query(0,n-1,1,i,i) != s[i] - '0') gg = true;
		}
		cout << (gg?"NO":"YES") << endl;
	}	
}