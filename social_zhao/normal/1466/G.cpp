#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5, M = 2e6 + 5, P = 1e9 + 7, inv2 = (P + 1) / 2;
int n, m, pw[N], ipw[N];
char s[20][M], t[M], w[M], tmp[M];
int len[20], mx, occ[N][26];

int nxt[M];
int calc(char *A, char *B, int lenA, int lenB) {
	if(lenA < lenB) return 0;
	A[lenA + 1] = B[lenB + 1] = 0;
	nxt[1] = 0;
	int ans = 0;
	for(int i = 2; i <= lenB; i++) {
		nxt[i] = nxt[i - 1];
		while(nxt[i] && B[i] != B[nxt[i] + 1]) nxt[i] = nxt[nxt[i]];
		if(B[i] == B[nxt[i] + 1]) ++nxt[i];
	}
	for(int i = 1, j = 0; i <= lenA; i++) {
		while(j && B[j + 1] != A[i]) j = nxt[j];
		if(A[i] == B[j + 1]) ++j;
		if(j == lenB) ++ans;
	}
	return ans;
}

void solve() {
	int k = get(), ans = 0, ln;
	scanf("%s", w + 1), ln = strlen(w + 1);
	ans = (ans + 1ll * calc(s[0], w, len[0], ln) * pw[k]) % P;
	for(int i = 1; i <= min(mx, k); i++) {
		int tl = 0, mid = (len[i] + 1) / 2;
		for(int j = max(1, mid - ln + 1); j <= min(len[i], mid + ln - 1); j++)
			tmp[++tl] = s[i][j];
		ans = (ans + 1ll * calc(tmp, w, tl, ln) * pw[k - i] % P) % P;
	}
	for(int i = 0; i < 26; i++) {
		int tl = 0;
		for(int j = len[mx] - (ln - 1) + 1; j <= len[mx]; j++) tmp[++tl] = s[mx][j];
		tmp[++tl] = 'a' + i;
		for(int j = 1; j <= ln - 1; j++) tmp[++tl] = s[mx][j];
		ans = (ans + 1ll * calc(tmp, w, tl, ln) * pw[k] % P * occ[k][i] % P) % P;
	}
	printf("%d\n", ans);
}

int main() {
	n = get(), m = get();
	pw[0] = ipw[0] = 1;
	for(int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 2ll % P, ipw[i] = 1ll * ipw[i - 1] * inv2 % P;
	scanf("%s", s[0] + 1), scanf("%s", t + 1);
	len[0] = strlen(s[0] + 1);
	for(int i = 1; i <= min(n, 20); i++) {
		for(int j = 1; j <= len[i - 1]; j++) s[i][++len[i]] = s[i - 1][j];
		s[i][++len[i]] = t[i];
		for(int j = 1; j <= len[i - 1]; j++) s[i][++len[i]] = s[i - 1][j];
		mx = i;
		if(len[i] > 1e6) break;
	}
	for(int i = mx + 1; i <= n; i++) {
		for(int j = 0; j < 26; j++) {
			if(t[i] - 'a' == j) occ[i][j] = (occ[i - 1][j] + ipw[i]) % P;
			else occ[i][j] = occ[i - 1][j];
		}
	}
	for(int i = 1; i <= m; i++) solve();
	return 0;
}