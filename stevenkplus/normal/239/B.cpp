#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 110;
char orig[MAXN];
char seq[MAXN];
bool in[MAXN];

int cnts[10];

int N, Q;
void go(int l, int r) {
	int dp = 1;
	int cp = l;
	int prcp = -1;
	bool prnum = true;
	while (cp >= l && cp <= r) {
		if (!in[cp]) {
			cp += dp;
		} else if (seq[cp] == '>' || seq[cp] == '<') {
			if (!prnum) {
				in[prcp] = false;
			}
			dp = (seq[cp] == '>')? 1 : -1;
			prnum = false;
			prcp = cp;
			cp += dp;
		} else {
			int num = seq[cp] - '0';
			cnts[num]++;
			if (num == 0) {
				in[cp] = false;
			} else {
				seq[cp]--;
			}
			prnum = true;
			prcp = cp;
			cp += dp;
		}
	}
}

void reset() {
	for(int i = 0; i < N; ++i) {
		seq[i] = orig[i];
		in[i] = true;
	}
	for(int i = 0; i < 10; ++i) {
		cnts[i] = 0;
	}
}

int main() {
	scanf("%d %d %s", &N, &Q, orig);
	for(int q = 0; q < Q; ++q) {
		int l, r;
		scanf("%d %d", &l, &r);
		reset();
		go(l - 1, r - 1);
		for(int i = 0; i < 10; ++i) {
			if (i > 0) {
				printf(" ");
			}
			printf("%d", cnts[i]);
		}
		printf("\n");
	}
	return 0;
}