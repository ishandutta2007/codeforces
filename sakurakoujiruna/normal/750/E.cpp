#include <bits/stdc++.h>
using namespace std;

void upd(int &x, int y) {
	if(x == -1 || x > y)
		x = y;
}

struct val {
	int f[5][5];
	val operator +(val v) {
		val r; r.f[4][4] = 0;
		for(int i = 0; i < 4; i ++)
			for(int j = i; j <= 4; j ++) {
				r.f[i][j] = -1;
				for(int k = i; k <= j; k ++)
					if((~f[i][k]) && (~v.f[k][j]))
						upd(r.f[i][j], f[i][k] + v.f[k][j]);
			}
		return r;
	}
};

const int N = 2e5L + 11;
val v[N * 4];

char s[N], t[N];

void build(int l, int r, int x = 1) {
	if(l + 1 == r) {
		for(int i = 0; i < 4; i ++)
			for(int j = i; j <= 4; j ++)
				v[x].f[i][j] = -1;
		for(int i = 0; i < 4; i ++)
			if(s[l] == t[i]) {
				v[x].f[i][i] = 1;
				v[x].f[i][i + 1] = 0;
			} else {
				v[x].f[i][i] = 0;
				v[x].f[i][i + 1] = -1;
			}
		v[x].f[4][4] = 0;
	} else {
		int m = (l + r) / 2;
		build(l, m, 2 * x);
		build(m, r, 2 * x + 1);
		v[x] = v[2 * x] + v[2 * x + 1];
	}
}

val query(int l, int r, int ql, int qr, int x = 1) {
	if(l == ql && r == qr) return v[x];
	int m = (l + r) / 2;
	if(qr <= m) return query(l, m, ql, qr, 2 * x);
	if(ql >= m) return query(m, r, ql, qr, 2 * x + 1);
	return query(l, m, ql, m, 2 * x) + query(m, r, m, qr, 2 * x + 1);
}

int sum[N];

int main() {
	int n, m; cin >> n >> m;
	scanf("%s", s + 1);
	t[0] = '2'; t[1] = '0'; t[2] = '1'; t[3] = '6';
	set <int> st = {0, n + 1};
	for(int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1];
		if(s[i] == '7')
			st.insert(i);
		else if(s[i] == '6')
			sum[i] ++;
	}
	build(1, n + 1);
	
	while(m --) {
		int a, b; cin >> a >> b;
		int x = *(-- st.upper_bound(b));
		
		if(x > a) {
			int sp = sum[b] - sum[x - 1];
			int t = query(1, n + 1, a, x).f[0][3];
			if(t == -1)
				puts("-1");
			else
				printf("%d\n", t + sp);
		} else
			puts("-1");	
	}
}