#include <bits/stdc++.h>

using namespace std;

#define N 2000005
#define mod 51123987

typedef long long LL;

struct PTree {
	char S[N];
	int head[N];
	int nxt[N];
	int ch[N], m;
	char nx[N];
	int fail[N], len[N], cnt[N];
	int last, sz, n;

	int newnode(int L) {
		cnt[sz] = 0, len[sz] = L;
		head[sz] = 0;
		return sz ++;
	}

	void init() {
		m = sz = n = 0, last = 1;
		newnode(0), newnode(-1);
		S[0] = 250, fail[0] = 1;
	}

	int getFail(int v) {
		while (S[n - len[v] - 1] != S[n]) v = fail[v];
		return v;
	}

	int add(int c) {
		S[++ n] = c;
		int cur = getFail(last), i, j;
		for(i = head[cur]; i; i = nxt[i]) if(nx[i] == c) break;
		if (!i) {
			int now = newnode(len[cur] + 2);
			int x = getFail(fail[cur]);
			for(j = head[x]; j; j = nxt[j]) if(nx[j] == c) break;
			if(j) fail[now] = ch[j]; else fail[now] = 0;
			nxt[++ m] = head[cur];
			head[cur] = m;
			nx[m] = c; ch[m] = now;
			cnt[now] = cnt[fail[now]] + 1;
			last = now;
		} else last = ch[i];
		return cnt[last];
	}
} P;

char s[N];
int sum[N];
int n;

main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	scanf("%s", s);
	sum[n] = 0, P.init();
	for (int i = n - 1; i >= 0; i --) {
		sum[i] = (sum[i + 1] + P.add(s[i] - 'a')) % mod;
	}
	P.init();
	LL rlt = 0;
	for (int i = 0; i < n; i ++) {
		rlt = (rlt + 1LL * P.add(s[i] - 'a') * sum[i + 1]) % mod;
	}
	printf("%I64d\n", ((1LL * sum[0] * sum[0] - sum[0]) / 2 - rlt + mod) % mod);
}