#include <bits/stdc++.h>
using namespace std;

#define N 101010

const long long INF = 1ll << 60;

char s[N] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char prv[N] = "What are you doing while sending _";
char mid[N] = "_? Are you busy? Will you send _";
char nxt[N] = "_?";

int X, Y, Z, S;

long long len[N];

void prep_len() {
	S = strlen(s);
	X = strlen(prv);
	prv[X-1] = 34;
	Y = strlen(mid);
	mid[0] = 34;
	mid[Y-1] = 34;
	Z = strlen(nxt);
	nxt[0] = 34;
	memset(len, -1, sizeof len);
	len[0] = S;
	for (int i = 1; i < N; i ++) {
		len[i] = len[i-1] * 2 + (X + Y + Z);
		if (len[i] > INF) {
			len[i] = -1;
			break;
		}
	}
}

char calc(int n, long long k) {
	if (n == 0) {
		if (k < S) return s[k];
		return '.';
	}
	if (k < X) return prv[k];
	k -= X;
	if (len[n-1] == -1 || k < len[n-1]) return calc(n - 1, k);
	k -= len[n-1];
	if (k < Y) return mid[k];
	k -= Y;
	if (k < len[n-1]) return calc(n - 1, k);
	k -= len[n-1];
	if (k < Z) return nxt[k];
	return '.';
}

char solve() {
	int n;
	long long k;
	scanf("%d %I64d\n", &n, &k);
	k --;
	return calc(n, k);
}

char ans[N];

int main() {
	//freopen("r.in", "r", stdin);
	//freopen("w.out", "w", stdout);
	prep_len();
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt ++) {
		ans[tt] = solve();
	}
	ans[t] = 0;
	puts(ans);

	return 0;
}