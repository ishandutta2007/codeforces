#include <cstdio>

using namespace std;

const int MAXN = 100100;

char str[MAXN];
int prefs[MAXN];

int N, Q;
int main() {
	scanf("%s", str);
	N = 0;
	while (str[N]) {
		if (str[N] == str[N + 1]) {
			prefs[N + 1] = prefs[N] + 1;
		} else {
			prefs[N + 1] = prefs[N];
		}
		++N;
	}
	scanf("%d", &Q);

	for(int i = 0; i < Q; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		--b;
		int ans = prefs[b] - prefs[a];
		printf("%d\n", ans);
	}

	return 0;
}