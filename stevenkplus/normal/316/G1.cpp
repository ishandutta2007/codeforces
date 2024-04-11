#include <cstdio>

using namespace std;

const int MAXN = 210;
const int MAXK = 11;

char str[MAXN];
char rules[MAXK][MAXN];
int minr[MAXK];
int maxr[MAXK];

int K;

int fail[MAXN];
void build(int l, int r) {
	fail[0] = -1;
	for(int i = 1; i <= r - l; ++i) {
		int f = fail[i - 1];
		while (f != -1 && str[l + i - 1] != str[l + f]) {
			f = fail[f];
		}
		++f;
		fail[i] = f;
	}
}

bool go(int l, int r, int k) {
	int cnt = 0;
	int cur = 0;
	char *rule = rules[k];
	for(int i = 0; rule[i]; ++i) {
		while (cur == r - l || (cur != -1 && rule[i] != str[l + cur])) {
			cur = fail[cur];
		}
		++cur;

		if (cur == r - l) {
			++cnt;
		}
	}
	return cnt >= minr[k] && cnt <= maxr[k];
}

int ansl[MAXN * MAXN], ansr[MAXN * MAXN];

int main() {
	scanf("%s", str);
	scanf("%d", &K);

	for(int i = 0; i < K; ++i) {
		scanf("%s %d %d", rules[i], minr + i, maxr + i);
	}

	int ans = 0;
	for(int l = 0; str[l]; ++l) {
		for(int r = l + 1; str[r - 1]; ++r) {
			build(l, r);
			bool good = true;
			for(int k = 0; k < K; ++k) {
				if (!go(l, r, k)) {
					good = false;
					break;
				}
			}

			if (good) {
				bool bad = false;
				for(int i = 0; i < ans; ++i) {
					if (ansr[i] - ansl[i] != r - l) continue;
					bool match = true;
					for(int j = 0; j < r - l; ++j) {
						if (str[ansl[i] + j] != str[l + j]) {
							match = false;
							break;
						}
					}
					if (match) {
						bad = true;
						break;
					}
				}

				if (!bad) {
					ansl[ans] = l;
					ansr[ans] = r;
					++ans;
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}