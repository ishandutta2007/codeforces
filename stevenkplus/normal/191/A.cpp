#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXC = 30;
int ar[MAXC][MAXC];

int N;
char buf[123456];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%s", buf);
		int start = buf[0] - 'a';
		int len;
		for(len = 0; buf[len]; ++len);
		int end = buf[len - 1] - 'a';
		for(int i = 0; i < MAXC; ++i) {
			if (ar[i][start] > 0) {
				ar[i][end] = max(ar[i][end], ar[i][start] + len);
			}
		}
		ar[start][end] = max(ar[start][end], len);
	}
	int m = 0;
	for(int i = 0; i < MAXC; ++i) {
		m = max(m, ar[i][i]);
	}
	printf("%d\n", m);
	return 0;
}