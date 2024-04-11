#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>
#include <stack>
#include <unordered_map>
using namespace std;

#define NN 524288
int n;
char *pa[NN];
int ps[NN];
int prv[NN]; // prv[i] = position, where value equal to a[i] was before or -1
int nxt[NN]; // prv[i] = position, where value equal to a[i] was after or -1
char inbuf[NN*12];
char outbuf[NN*12];
unordered_map<int,int> last(NN);
int stk[NN], stk_len;
pair<int,int> best;
int result[NN][2], r_size;

int main() {
	fread(inbuf, sizeof(inbuf), 1, stdin);
	char *p;
	for (p = inbuf; *p >= '0' && *p <= '9'; ++p) n = n * 10 + (*p - '0');
	for (int i = 0; i < n; ++i) {
		int a = 0;
		while (*p < '0') ++p;
		pa[i] = p;
		for (; *p >= '0' && *p <= '9'; ++p) a = a * 10 + (*p - '0');
		*p = ' ';
		ps[i] = p-pa[i]+1;
		prv[i] = last[a]-1;
		nxt[i] = -1;
		if (prv[i] != -1) {
			nxt[prv[i]] = i;
		}
		last[a] = i+1;
	}
	best.second = n;
	for (int i = 0; i < n; ++i) {
		if (i == best.second) {
			result[r_size][0] = best.first;
			result[r_size++][1] = best.second;
			best.second = n;
			stk_len = 0;
			continue;
		}
		if (stk_len && i == stk[stk_len - 1]) {
			--stk_len;
		}
		if (nxt[i] == -1) continue;
		if (stk_len && nxt[i] > stk[stk_len - 1]) {
			if (best.second > nxt[i]) {
				best = make_pair(stk[stk_len - 1], nxt[i]);
			}
		} else if (prv[i] != -1 && prv[prv[i]] != -1 && (r_size == 0 || prv[prv[i]] > result[r_size - 1][1])) {
			if (best.second > nxt[i]) {
				best = make_pair(i, nxt[i]);
			}
		} else {
			stk[stk_len++] = nxt[i];
		}
	}
	sprintf(outbuf, "%d\n", r_size*4);
	p = outbuf + strlen(outbuf);
	for (int i = 0; i < r_size; ++i) {
		char *pa1 = pa[result[i][0]];
		char *pa2 = pa[result[i][1]];
		int ps1 = ps[result[i][0]];
		int ps2 = ps[result[i][1]];
		memcpy(p, pa1, ps1); p += ps1;
		memcpy(p, pa2, ps2); p += ps2;
		memcpy(p, pa1, ps1); p += ps1;
		memcpy(p, pa2, ps2); p += ps2;
	}
	*p++ = '\n';
	fwrite (outbuf, p-outbuf, 1, stdout);
	return 0;
}

/* vim: set ts=4 sw=4 noet: */