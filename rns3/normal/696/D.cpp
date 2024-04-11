#include <bits/stdc++.h>
using namespace std;

const long long INF = 1ll * 2e9 * 1e9;

#define N 202
const int K = 26;

struct AhoCT {
	struct node {
		int nxt[26], link, cnt;
	} node[N];

	int sz;

	int newnode() {
		memset(node[sz].nxt, 0, sizeof node[sz].nxt);
		node[sz].link = node[sz].cnt = 0;
		return sz ++;
	}

	void init() {sz = 0, newnode();}

	void insert(char *s, int &val) {//puts(s);
		int u = 0;
		for (int i = 0, c; s[i]; i ++) {
			c = s[i] - 'a';
			if (!node[u].nxt[c]) node[u].nxt[c] = newnode();
			u = node[u].nxt[c];
		}
		node[u].cnt += val;
	}

	int e, q[N];

	void get_link() {
		int u = 0;
		e = 0;
		for (int c = 0; c < K; c ++) if (node[u].nxt[c]) q[e++] = node[u].nxt[c];
		for (int f = 0; f < e; f ++) {
			u = q[f];
			for (int c = 0; c < K; c ++) {
				if (node[u].nxt[c]) {
					q[e++] = node[u].nxt[c];
					node[node[u].nxt[c]].link = node[node[u].link].nxt[c];
					node[node[u].nxt[c]].cnt += node[node[node[u].nxt[c]].link].cnt;
				}
				else node[u].nxt[c] = node[node[u].link].nxt[c];
			}
		}
	}
} ACT;

struct matrix {
	long long a[N][N], n;
	void init(int sz = 0) {
		n = sz;
		for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) a[i][j] = -INF;
	}
	inline matrix operator * (const matrix &B) const {
		matrix C;
		C.init(max(B.n, n));
		for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) for (int k = 0; k < n; k ++) C.a[i][j] = max(C.a[i][j], a[i][k] + B.a[k][j]);
		return C;
	}
} A, B;

int n, a[N];
char s[N];

int main() {
	//freopen("r.in", "r", stdin);
	long long len;
	scanf("%d %I64d", &n, &len);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	ACT.init();
	for (int i = 1; i <= n; i ++) scanf("%s", s), ACT.insert(s, a[i]);
	ACT.get_link();
	int m = ACT.sz;
	B.init(m);
	A.init(m);
	for (int i = 0; i < m; i ++) for (int c = 0; c < K; c ++) A.a[i][ACT.node[i].nxt[c]] = ACT.node[ACT.node[i].nxt[c]].cnt;
	B.a[0][0] = 0;
	while (1) {
		if (len % 2) B = B * A;
		len /= 2;
		if (!len) break;
		A = A * A;
	}
	long long rlt = 0;
	for (int i = 0; i < m; i ++) rlt = max(rlt, B.a[0][i]);
	printf("%I64d\n", rlt);

	return 0;
}