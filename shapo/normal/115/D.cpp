#include <cctype>
#include <cstdio>
#include <cstring>

#define MAXN 2100

char s[MAXN];
int res[MAXN][MAXN];

int next_int (const char *s, const int &cur_pos) {
	int pos = cur_pos;
	while (isdigit (s[pos++]));
	return pos - 1;
}

inline void upd (int fi, int fj, int si, int sj) {
	res[si][sj] = (res[si][sj] + res[fi][fj]) % 1000003;
}

int main () {
	scanf (" %s", s);
	int len = strlen(s);
	int next_pos;
	res[0][0] = 1;
	int ans = 0;
	for (int i = 0; i < len; ++i) {
		if (isdigit (s[i]))
			next_pos = next_int (s, i);
		for (int cnt = 0; cnt < len; ++cnt) {
			upd (i, cnt, i, cnt + 1);
			if (isdigit (s[i])) {
				if (next_pos == len) {
					if (!cnt)
						ans = (ans + res[i][cnt]) % 1000003;
				} else if (cnt)
					upd (i, cnt, next_pos + 1, cnt - 1);
			} else
				if (s[i] == '+' || s[i] == '-')
					upd (i, cnt, i + 1, cnt);
		}
	}
	printf ("%d\n", ans);
	return 0;
}