//============================================================================
// Name        : Xenia.cpp
// Author      : mHm
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

#define L 100100

const int LEN = L * 3;

int r[LEN], sa[LEN];
int wa[LEN], wb[LEN], wv[LEN], ss[LEN];

#define F(x) ((x) / 3 + ((x) % 3 == 1 ? 0 : tb))
#define G(x) ((x) < tb ? (x) * 3 + 1 : ((x) - tb) * 3 + 2)

int c0(int *r, int a, int b) { return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2]; }

int c12(int k, int *r, int a, int b) {
	if (k == 2) return r[a] < r[b] || (r[a] == r[b] && c12(1, r, a + 1, b + 1));
	return r[a] < r[b] || (r[a] == r[b] && wv[a + 1] < wv[b + 1]);
}

void sort(int *r, int *a, int *b, int n, int m) {
	for (int i = 0; i < n; i ++) wv[i] = r[a[i]];
	for (int i = 0; i < m; i ++) ss[i] = 0;
	for (int i = 0; i < n; i ++) ss[wv[i]] ++;
	for (int i = 1; i < m; i ++) ss[i] += ss[i - 1];
	for (int i = n - 1; i >= 0; i --) b[-- ss[wv[i]]] = a[i];
}

void DC3(int *r, int *sa, int n, int m) {
	int i, j, p;
	int *san = sa + n, *rn = r + n;
	int ta = 0, tb = (n + 1) / 3, tbc = 0;

	r[n] = r[n + 1] = 0;
	for (i = 0; i < n; i ++) if (i % 3 != 0) wa[tbc ++] = i;

	sort(r + 2, wa, wb, tbc, m);
	sort(r + 1, wb, wa, tbc, m);
	sort(r, wa, wb, tbc, m);

	for (p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i ++)
		rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p ++;

	if (p < tbc) DC3(rn, san, tbc, p);
	else for (i = 0; i < tbc; i ++) san[rn[i]] = i;

	for (i = 0; i < tbc; i ++) if (san[i] < tb) wb[ta ++] = san[i] * 3;
	if (n % 3 == 1) wb[ta ++] = n - 1;

	sort(r, wb, wa, ta, m);

	for (i = 0; i < tbc; i ++) wv[wb[i] = G(san[i])] = i;
	for (i = 0, j = 0, p = 0; i < ta && j < tbc; p ++)
		sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i ++] : wb[j ++];

	for ( ; i < ta; p ++) sa[p] = wa[i ++];
	for ( ; j < tbc; p ++) sa[p] = wb[j ++];
}

int rnk[L], lcp[18][L];

void calc_LCP(int *r, int *sa, int n) {
	int k = 0;
	for (int i = 0; i < n; i ++) rnk[sa[i]] = i;
	for (int i = 0; i < n - 1; lcp[0][rnk[i ++]] = k) {
		if (k) k --;
		for (int j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k ++);
	}
	for(int j = 1; j < 18; j ++) {
		for(int i = (1<<j); i < n; i ++) {
			lcp[j][i] = min(lcp[j-1][i], lcp[j-1][i - (1<<(j-1))]);
		}
	}
}

char s[L];
int n, B;
bool f[L][18];
int can[L][18];
int val[L][18];

int calc(int x, int y) {
	x = rnk[x]; y = rnk[y];
	if(x > y) swap(x, y);
	int i = 0;
	while(x + (1<<i) <= y) i ++;
	i --;
	return min(lcp[i][y], lcp[i][x + (1<<i)]);
}

long long ans, cur[L];
int q[L * 20];

void run() {
	for(int i = 0; i < n; i ++) f[i][1] = 1, val[i][1] = 1<<(s[i] - 'a');
	ans = n;
	for(int j = 2; j <= B; j ++) {
		for(int i = 0; i < n; i ++) {
			if(i + (1<<j) - 1 <= n) {
				int k = s[i + (1<<(j-1)) - 1] - 'a';
				if(f[i][j - 1] && !(val[i][j - 1] & (1<<k))) {
					if(f[i + (1<<(j-1))][j-1] && calc(i, i + (1<<(j-1))) >= (1<<(j-1)) - 1) {
						f[i][j] = 1; val[i][j] = val[i][j-1] | (1<<k);
						ans += 1LL * ((1<<j) - 1) * ((1<<j) - 1);
						for(int t = 0; t < (1<<j) - 1; t ++) cur[t + i] += 1LL * ((1<<j) - 1) * ((1<<j) - 1);
					}
				}
			}
		}
	}
	long long curans = ans;
	if(B < 2) return;
	for(int i = 0; i < n; i ++) {
		long long mx = 0;
		for(int t = 0; t < 26; t ++) if(s[i] - 'a' != t) {
			long long tp = 0;
			int hd = 0, tl = 0;
			q[tl ++] = i;
			for(int d = 2; d <= B; d ++) {
				int len = tl - hd;
				while(len --) {
					int pos = q[hd ++], nxt = pos + (1<<(d-1)), cen = pos + (1<<(d-2)) - 1;
					if(nxt < n && f[nxt][d-1] && !(val[nxt][d-1] & (1<<(s[nxt-1] - 'a')))) {
						bool ok = 0;
						if(i == cen) {
							if(t == s[nxt+(1<<(d-2))-1]-'a' && calc(pos, nxt) >= (1<<(d-2))-1) ok = 1;
						} else if(i < cen) {
							if(calc(pos+(1<<(d-2))-1, nxt+(1<<(d-2))-1) >= (1<<(d-2))) ok = 1;
						} else {
							if(calc(pos, nxt) >= (1<<(d-2))) ok = 1;
						}
						if(ok) {
							q[tl ++] = pos; tp += 1LL * ((1<<d)-1) * ((1<<d)-1);
						}
					}

					nxt = pos - (1<<(d-1));

					if(nxt >= 0 && f[nxt][d-1] && !(val[nxt][d-1] & (1<<(s[pos-1] - 'a')))) {
						bool ok = 0;
						if(i == cen) {
							if(t == s[nxt+(1<<(d-2))-1]-'a' && calc(pos, nxt) >= (1<<(d-2))-1) ok = 1;
						} else if(i < cen) {
							if(calc(pos+(1<<(d-2))-1, nxt+(1<<(d-2))-1) >= (1<<(d-2))) ok = 1;
						} else {
							if(calc(pos, nxt) >= (1<<(d-2))) ok = 1;
						}
						if(ok) {
							q[tl ++] = nxt; tp += 1LL * ((1<<d)-1) * ((1<<d)-1);
						}
					}

					nxt = i - (1<<(d-1)) + 1;
					if(nxt >= 0 && f[nxt][d-1] && f[i+1][d-1] && !(val[nxt][d-1] & (1<<(t)))){
						if(calc(nxt, i + 1) >= (1<<(d-1)) - 1) {
							q[tl ++] = nxt; tp += 1LL * ((1<<d) - 1) * ((1<<d) - 1);
						}
					}
				}
			}
			mx = max(mx, tp);
		}
		//cout << ans << endl;
		//cout << "cur[" << i << "] = " << cur[i] << endl;
		ans = max(ans, curans - cur[i] + mx);
	}
}

int main() {
	//freopen("X.in", "r", stdin);
	gets(s);
	n = strlen(s);
	for(int i = 0; i < n; i ++) r[i] = s[i];
	r[n] = 0;
	DC3(r, sa, n + 1, 256);
	calc_LCP(r, sa, n + 1);
	B = 1;
	while((1<<B) - 1 <= n) B ++;
	B --;
	run();
	printf("%I64d\n", ans);
	return 0;
}