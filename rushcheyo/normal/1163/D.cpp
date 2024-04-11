#include <cstdio>
#include <cstring>

int fails[55], transs[55][26], failt[55], transt[55][26], f[1005][55][55];
char cs[1005], s[55], t[55];

void get(char *s, int len, int *fail, int trans[55][26]) {
	for (int i = 0; i < len; ++i)
		trans[i][s[i + 1] - 'a'] = i + 1;
	for (int i = 1; i < len; ++i)
		for (int c = 0; c < 26; ++c)
			(trans[i][c] ? fail[trans[i][c]] : trans[i][c]) = trans[fail[i]][c];
}

void upd(int &a, int b) {
	if (a < b) a = b;
}

int main() {
	scanf("%s%s%s", cs + 1, s + 1, t + 1);
	int n = strlen(cs + 1), ls = strlen(s + 1), lt = strlen(t + 1);
	get(s, ls, fails, transs);
	get(t, lt, failt, transt);
	memset(f, -0x3f, sizeof f);
	f[0][0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int ps = 0; ps < ls; ++ps)
			for (int pt = 0; pt < lt; ++pt)
				if (f[i - 1][ps][pt] > -1000000)
					for (int c = (cs[i] == '*' ? 0 : cs[i] - 'a'); c <= (cs[i] == '*' ? 25 : cs[i] - 'a'); ++c)
						upd(f[i][transs[ps][c] == ls ? fails[ls] : transs[ps][c]][transt[pt][c] == lt ? failt[lt] : transt[pt][c]],
							f[i - 1][ps][pt] + (transs[ps][c] == ls) - (transt[pt][c] == lt));
	int ans = -1000000;
	for (int ps = 0; ps < ls; ++ps)
		for (int pt = 0; pt < lt; ++pt)
			upd(ans, f[n][ps][pt]);
	printf("%d\n", ans);
	return 0;
}