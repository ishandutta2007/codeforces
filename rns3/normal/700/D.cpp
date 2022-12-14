#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define K 300
#define M 1010

struct query {
	int st, en;
	long long ans;
}Q[N];

int T, n, w[N], x, y;

vector <int> id[N];

int c[N], cc[N], in[N], cnt, rmh[M], ris[2*M];

void ins(int a, int b) {
	cc[c[a]] --;
	c[a] += b;
	cc[c[a]] ++;
	if (c[a] >= 2 * K && !in[a]) {
		in[a] = 1;
		rmh[++cnt] = a;
	}
}

priority_queue <int> PQ;

int Top() {
	int rlt = PQ.top();
	PQ.pop();
	return rlt;
}

void solve(int pb, int ii) {
	int b = Q[ii].st;
	long long rlt = 0;
	for (int i = pb; i < b; i ++) ins(w[i], -1);
	for (int i = 1; i <= cnt; i ++) if (c[rmh[i]] >= 2 * K) PQ.push(-c[rmh[i]]);
	for (int i = 1; i < 2 * K; i ++) ris[i] = cc[i];
	for (int i = 2 * K; i <= 4 * K; i ++) ris[i] = 0;
	for (int i = 1, j; i < 2 * K; i ++) {
		ris[i*2] += ris[i] / 2;
		rlt += (ris[i] / 2) * 2 * i;
		ris[i] %= 2;
		if (ris[i]) {
			for (j = i + 1; j < 2 * K && !ris[j]; j ++);
            if (j != 2 * K) {
				ris[j] --;
				ris[i] --;
				ris[i+j] ++;
				rlt += i + j;
				i = j - 1;
				continue;
            }
            else {
				PQ.push(-i);
				break;
            }
		}
	}
	for (int i = 2 * K; i <= 4 * K; i ++) while (ris[i]) {
		ris[i] --;
		PQ.push(-i);
	}
	while (PQ.size() > 1) {
		int t1 = Top(), t2 = Top();
		rlt -= (t1 + t2);
		PQ.push(t1 + t2);
	}
	while (!PQ.empty()) PQ.pop();
	for (int i = pb; i < b; i ++) ins(w[i], 1);
	Q[ii].ans = rlt;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    scanf("%d", &T);
    for (int i = 1; i <= T; i ++) {
		scanf("%d %d", &x, &y);
		Q[i].st = x;
		Q[i].en = y;
		id[y].push_back(i);
    }
    for (int i = 1; i <= n; i += K) {
		memset(c, 0, sizeof c);
		memset(cc, 0, sizeof cc);
		memset(in, 0, sizeof in);
		cnt = 0;
		for (int j = i; j <= n; j ++) {
			ins(w[j], 1);
			for (int k = 0, sz = id[j].size(); k < sz; k ++) if (Q[id[j][k]].st >= i && Q[id[j][k]].st < i + K) solve(i, id[j][k]);
		}
    }
    for (int i = 1; i <= T; i ++) printf("%I64d\n", Q[i].ans);
	return 0;
}