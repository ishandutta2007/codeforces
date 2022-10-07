#include <cstdio>

using namespace std;

const int MAXN = 110;

char A[MAXN];
char B[MAXN];

bool vis[MAXN];
int rnd[MAXN];
int cnts[MAXN];

int N, M;

int main() {
	scanf("%d %d", &N, &M);
	scanf("%s", A);
	scanf("%s", B);

	int cnt = 0;
	int pos = 0;
	for(int i = 0; i < N;) {
		int pri = i;
		if (vis[pos]) {
			int per = i - rnd[pos];
			int num = cnt - cnts[pos];
			int skip = (N - i) / per;
			i += per * skip;
			cnt += num * skip;
		}
		if (i == pri) {
			vis[pos] = true;
			cnts[pos] = cnt;
			rnd[pos] = i;
			for(int j = 0; A[j]; ++j) {
				if (A[j] == B[pos]) {
					++pos;
					if (!B[pos]) {
						pos = 0;
						++cnt;
					}
				}
			}
			++i;
		}
	}
	cnt /= M;
	printf("%d\n", cnt);

	return 0;
}