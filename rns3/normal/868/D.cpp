#include <bits/stdc++.h>
using namespace std;

#define N 102

char s[N];

const int K = 10;

const int M = 1 << (K + 1);

struct data {
	char prf[K], suf[K];
	int sz;
	bitset <M> b;

	void init() {
		b = 0;
		b[1] = 1;
		memset(prf, -1, sizeof prf);
		memset(suf, -1, sizeof suf);
	}

	void get(char *s) {
		init();
		int n = strlen(s);
		for (int i = 0; i < n; i ++) {
			int now = 0;
			for (int j = i; j < min(i + K, n); j ++) {
				now = now * 2 + s[j] - '0';
				b[now+(1<<(j-i+1))] = 1;
			}
		}
		for (int i = 0; i < min(n, K); i ++) prf[i] = s[i];
		for (int i = K - 1, j = n - 1; i >= 0 && j >= 0; i --, j --) suf[i] = s[j];
		sz = min(n, K);
	}
};

char tmp[K<<2];

int join(data &A, data &B, data &C) {
	C.init();
	for (int i = 0; i < K; i ++) C.prf[i] = A.prf[i];
	for (int i = 0; i < K; i ++) C.suf[i] = B.suf[i];
	if (A.sz < K) {
		for (int i = A.sz, j = 0; i < K && j < B.sz; i ++, j ++) C.prf[i] = B.prf[j];
	}
	if (B.sz < K) {
		for (int i = K - B.sz - 1, j = K - 1; i >= 0 && j >= K - A.sz; i --, j --) C.suf[i] = A.suf[j];
	}
	C.b = A.b | B.b;

	int e = 0;
	for (int i = K - A.sz; i < K; i ++) tmp[e++] = A.suf[i];
	for (int i = 0; i < B.sz; i ++) tmp[e++] = B.prf[i];



	for (int i = 0; i < e; i ++) {
		int now = 0;
		for (int j = i; j < min(i + K, e); j ++) {
			now = now * 2 + tmp[j] - '0';
			C.b[now+(1<<(j-i+1))] = 1;
		}
	}
	int ans = -1, t = 1;
	while (C.b[t]) {
		t ++;
		if (t == (t & (-t))) ans ++;
	}


	C.sz = min(K, A.sz + B.sz);
	return ans;
}

data D[N<<1];

int main() {
	//freopen("r.in", "r", stdin);
	int n, m;
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i ++) {
		gets(s);
		D[i].get(s);
	}
	scanf("%d", &m);
	for (int i = n + 1; i <= n + m; i ++) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", join(D[x], D[y], D[i]));
	}


	return 0;
}