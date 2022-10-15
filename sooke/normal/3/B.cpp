#include <cstdio>
#include <algorithm>
#define Maxn 100002

using namespace std;

struct Num {
	int w, i;
};

bool Cmp(Num a, Num b) {
	return a.w > b.w;
}

Num S1[Maxn], S2[Maxn];
int n, m, ans = 0, ansi, ansj, n1, n2, sum1, sum2;
bool flag = true;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int t, w;
		scanf("%d%d", &t, &w);
		if (t == 1) {
			S1[++n1] = (Num){w, i};
		} else {
			sum2 += w;
			S2[++n2] = (Num){w, i};
		}
	}
	sort(S1 + 1, S1 + n1 + 1, Cmp);
	sort(S2 + 1, S2 + n2 + 1, Cmp);
	for (int i = 0, j = n2; i <= n1; i++) {
		sum1 += S1[i].w;
		while (j >= 1 && i + j * 2 > m) {
			sum2 -= S2[j].w;
			j--;
		}
		if (i + j * 2 <= m) {
			if (ans < sum1 + sum2) {
				ans = sum1 + sum2;
				ansi = i;
				ansj = j;
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= ansi; i++) {
		if (flag) {
			flag = false;
			printf("%d", S1[i].i);
		} else {
			printf(" %d", S1[i].i);
		}
	}
	for (int j = 1; j <= ansj; j++) {
		if (flag) {
			flag = false;
			printf("%d", S2[j].i);
		} else {
			printf(" %d", S2[j].i);
		}
	}
	return 0;
}

// By Sooke.
// CF3B Lorry.