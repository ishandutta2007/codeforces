#include <bits/stdc++.h>
using namespace std;

const int N = 100005, INF = 1000000000;
int n, q, l[N], r[N], fp[N], fl[N], fr[N], cp, dp, clk, sum[N * 10][10];
bool vis[N];
char s[N];

void go_left() {
	fl[cp] = min(fl[cp], clk);
	while (s[l[cp]] == ' ') {
		fl[l[cp]] = min(fl[l[cp]], clk);
		l[cp] = l[l[cp]];
	}
	cp = l[cp];
}

void go_right() {
	fr[cp] = min(fr[cp], clk);
	while (s[r[cp]] == ' ') {
		fr[r[cp]] = min(fr[r[cp]], clk);
		r[cp] = r[r[cp]];
	}
	cp = r[cp];
}

void solve(int st) {
	cp = st, dp = 1;
	while (st <= cp && cp <= n) {
		vis[cp] = true;
		fp[cp] = min(fp[cp], ++clk);
		int tmp = cp;
		if (s[cp] == '<') {
			go_left();
			if (s[cp] == '<' || s[cp] == '>') s[tmp] = ' ';
			dp = -1;
		} else if (s[cp] == '>') {
			go_right();
			if (s[cp] == '<' || s[cp] == '>') s[tmp] = ' ';
			dp = 1;
		} else {
			sum[clk][s[cp] - '0'] = 1;
			if (s[cp] == '0') s[cp] = ' ';
			else s[cp]--;
			dp < 0 ? go_left() : go_right();
		}
	}
}

int main() {
	scanf("%d%d%s", &n, &q, s + 1);
	for (int i = 1; i <= n; i++) {
		l[i] = i - 1;
		r[i] = i + 1;
		fp[i] = fl[i] = fr[i] = INF;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) solve(i);
	for (int i = 1; i <= clk; i++)
		for (int j = 0; j <= 9; j++)
			sum[i][j] += sum[i - 1][j];
	for (int l, r; q--;) {
		scanf("%d%d", &l, &r);
		int st = fp[l], ed = min(min(fl[l], fr[r]), clk);
		for (int i = 0; i <= 9; i++) printf("%d%c", sum[ed][i] - sum[st - 1][i], " \n"[i == 9]);
	}
	return 0;
}