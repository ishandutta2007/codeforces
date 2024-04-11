#include <bits/stdc++.h>
using namespace std;

#define N 5050
#define M 505

int ten[N*M];

int fir[10*M], dlen[10*M], e;

int dp[N][M], len[N][M];
pair <int, int> go[N][M];

void check_max(int s, int r, int nlen, int f, int o_s, int o_r) {
	if (dp[s][r] == -1 || len[s][r] > nlen || (len[s][r] == nlen && fir[dp[s][r]] > fir[f])) {
		dp[s][r] = f;
		len[s][r] = nlen;
		go[s][r] = make_pair(o_s, o_r);
	}
}

void put(int f) {
	printf("%d", fir[f]);
	for (int step = 1; step < dlen[f]; step ++) printf("0");
}

int main() {
	int mod, S;
	scanf("%d %d", &mod, &S);
	ten[0] = 1;
	for (int i = 1; i < N * M; i ++) ten[i] = (ten[i-1] * 10) % mod;
	for (int j = 1; j <= mod; j ++) for (int i = 1; i <= 9; i ++) {
		fir[++e] = i;
		dlen[e] = j;
	}
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0, len[0][0] = 0;
	for (int s = 0; s < S; s ++) {
		for (int r = 0; r < mod; r ++) {
			if (dp[s][r] == -1) continue;
			int to = (s < S - 20) ? min(5 * 9, e): e;
			for (int f = 1; f <= to; f ++) {
				int nlen = dlen[f] + len[s][r];
				int ns = s + fir[f];
				int nr = (r + ten[dlen[f]-1+len[s][r]] * fir[f]) % mod;
				check_max(ns, nr, nlen, f, s, r);
			}
		}
	}
	if (dp[S][0] == -1) puts("-1");
	else {
		int s = S, r = 0;
		while (s) {
			put(dp[s][r]);
			int ss = go[s][r].first;
			int rr = go[s][r].second;
			s = ss, r = rr;
		}
	}


	return 0;
}