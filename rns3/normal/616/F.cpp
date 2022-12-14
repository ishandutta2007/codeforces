#include <cstdio>
#include <memory.h>

#define N 500010

typedef __int64 LL;

const int SIZE = N << 1;
const int SIGMA = 26;

struct Node {
	LL tot;
	int link, deep;
	int next[SIGMA];
	void clear() {
		link = -1;
		tot = deep = 0;
		memset(next, -1, sizeof(next));
	}
};

struct SuffixAutomaton {

	Node node[SIZE];
	int size, last;

	void init() {
		node[0].clear();
		size = 1;
		last = 0;
	}

	void insert(int c, int cost) {
		if (node[last].next[c] != -1) {
			int p = last, q = node[last].next[c];
			if (node[q].deep == node[p].deep + 1) {
				node[q].tot += cost;
				last = q;
				return;
			}
            int clone = size ++;
            node[clone] = node[q];
            node[clone].tot = cost;
            node[clone].deep = node[p].deep + 1;
            node[q].link = clone;
            while (p != -1 && node[p].next[c] == q) {
				node[p].next[c] = clone;
				p = node[p].link;
			}
			last = clone;
			return;
		}
		int cur = size ++;
		node[cur].clear();
		node[cur].tot = cost;
		node[cur].deep = node[last].deep + 1;

		int p = last;

		while (p != -1 && node[p].next[c] == -1) {
			node[p].next[c] = cur;
			p = node[p].link;
		}

		if (p == -1) node[cur].link = 0;
		else {
			int q = node[p].next[c];
			if (node[q].deep == node[p].deep + 1) node[cur].link = q;
			else {
				int clone = size ++;
				node[clone] = node[q];
				node[clone].tot = 0;
				node[clone].deep = node[p].deep + 1;
				node[cur].link = node[q].link = clone;

				while (p != -1 && node[p].next[c] == q) {
					node[p].next[c] = clone;
					p = node[p].link;
				}
			}
		}

		last = cur;
	}

	int cnt[N], ord[SIZE];

	LL build() {
		LL rlt = 0;
		for (int i = 0; i < N; i++) cnt[i] = 0;
		for (int i = 0; i < size; i ++) cnt[node[i].deep] ++;
		for (int i = 1; i < N; i ++) cnt[i] += cnt[i - 1];
		for (int i = 0; i < size; i ++) ord[-- cnt[node[i].deep]] = i;
		for (int i = size - 1; i >= 0; i --) {
			int cur = ord[i];
			int prv = node[cur].link;
			node[prv].tot += node[cur].tot;
			if (rlt < node[cur].tot * node[cur].deep) {
				rlt = node[cur].tot * node[cur].deep;
			}
		}
		return rlt;
	}
} SAM;

char s[N];
int len[N];

main() {
	int n, cur = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%s", s + cur);
		len[i] = strlen(s + cur);
		cur += len[i];
	}
	SAM.init();
	for (int i = 0, ps = 0; i < n; i ++) {
		int cost;
		scanf("%d", &cost);
		SAM.last = 0;
		for (int j = ps; j < ps + len[i]; j ++) {
			SAM.insert(s[j] - 'a', cost);
		}
		ps += len[i];
	}
	printf("%I64d\n", SAM.build());
}