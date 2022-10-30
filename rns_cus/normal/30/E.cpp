///	E : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;

#define N 200200

using namespace std;

char s[N], S[N];
int rad[N], h[N], m, n, mxh[N];
int stm, enm, stp, enp, sts, ens;

void make_PI() {
	int k = 0;
	m = strlen(S);
	h[1] = 0;
	for (int i = 2; i <= m; i ++) {
		while (k && S[k] != S[i-1]) k = h[k];
		if (S[k] == S[i-1]) k ++;
		h[i] = k;
	}
	for (int i = 0; i < m; i ++) h[i] = h[i+1];
}

void Manacher(char *s) {
	int n = strlen(s);
	int rlt = 0;
	for (int i = 0, j = 0, k; i < n * 2 - 1; i += k, j = max(j - k, 0)) {
		while (i - j >= 0 && i + j + 1 < n * 2 && s[(i - j) / 2] == s[(i + j + 1) / 2]) j ++;
		rad[i] = j;
		for (k = 1; i - k >= 0 && rad[i] - k >= 0 && rad[i-k] != rad[i] - k; k ++) rad[i+k] = min(rad[i - k], rad[i] - k);
	}
	for (int i = 0; i < n; i ++) rad[i] = rad[i<<1];
}

int calc(int i) {
	int rlt = rad[i];
	int x = i - rad[i] / 2, y = i + rad[i] / 2 + 1;
	if (!x || y >= n) return rlt;
	return rlt + 2 * min(x, mxh[n-y]);
}

int main() {
//	freopen("e.in", "r", stdin);
	cin >> s;
	n = strlen(s);
	reverse(s, s + n);
	Manacher(s);
	strcpy(S, s);
	strcat(S, "*");
	reverse(s, s + n);
	strcat(S, s);
	make_PI();

    for (int i = 1; i <= n; i ++) mxh[i] = max(mxh[i-1], h[n+i]);

	int mx = 0, mid = 0;
	for (int i = 0; i < n; i ++) {
		int x = calc(i);
		if (mx < x) mx = x, mid = i;
	}
	stm = mid - rad[mid] / 2, enm = mid + rad[mid] / 2;

	mx = 0;
	for (int i = enm + 1; i < n; i ++) {
		if (h[2*n-i] <= stm && mx < h[2*n-i]) mx = h[2*n-i], sts = i;
	}

	if (!mx) {
		puts("1");
		printf("%d %d\n", n - enm, rad[mid]);
		return 0;
	}

	enp = mx - 1;
	ens = sts + mx - 1;
	puts("3");
	printf("%d %d\n", n - ens, mx);
	printf("%d %d\n", n - enm, rad[mid]);
	printf("%d %d\n", n - enp, mx);
	return 0;
}