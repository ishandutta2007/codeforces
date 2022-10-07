#include <cstdio>

using namespace std;

const int MAXC = 30;

int conv(char c) {
	return c - 'a';
}

const int MAXN = 5010;

char s1[MAXN];
char s2[MAXN];
char ans[MAXN];

int N, M;
int cnts[MAXC];

int main() {
	scanf("%s", s1);
	scanf("%s", s2);

	N = 0;
	while (s1[N]) {
		++cnts[conv(s1[N])];
		++N;
	}

	int cur = 0;
	while (s2[cur] && cnts[conv(s2[cur])]) {
		--cnts[conv(s2[cur])];
		ans[cur] = s2[cur];
		++cur;
	}

	while (true) {
		char nxt = 0;
		char begin = 'a';
		if (s2[cur]) begin = s2[cur] + 1;
		for(char c = begin; c <= 'z'; ++c) {
			if (cnts[conv(c)]) {
				nxt = c;
				break;
			}
		}

		if (nxt) {
			ans[cur] = nxt;
			--cnts[conv(nxt)];
			++cur;
			break;
		} else {
			--cur;
			if (cur < 0) {
				printf("-1\n");
				return 0;
			}
			++cnts[conv(s2[cur])];
		}
	}


	for(char c = 'a'; c <= 'z'; ++c) {
		while (cnts[conv(c)]) {
			ans[cur] = c;
			++cur;
			--cnts[conv(c)];
		}
	}

	printf("%s\n", ans);
	return 0;
}