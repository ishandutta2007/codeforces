#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <vector>

#define maxn 500100
#define maxk 26

using namespace std;

int f[maxn], s[maxn];
int sz[maxk][maxk], tmpsz[maxk][maxk];
int n;
int len[maxn];
char tmp[maxk], ln;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf (" %s", tmp);
		ln = strlen(tmp);
		len[i] = ln;
		f[i] = tmp[0] - 'a';
		s[i] = tmp[ln - 1] - 'a';
	}
	for (int i = 0; i < maxk; ++i)
		for (int j = 0; j < maxk; ++j)
			sz[i][j] = 0;
	for (int i = 0; i < n; ++i) {
		memset (tmpsz, 0, sizeof (tmpsz));
		for (int j = 0; j < maxk; ++j)
			if (sz[j][f[i]])
				tmpsz[j][s[i]] = max (sz[j][s[i]], sz[j][f[i]] + len[i]);
			else 
				tmpsz[j][s[i]] = sz[j][s[i]];
		tmpsz[f[i]][s[i]] = max (tmpsz[f[i]][s[i]], max (sz[f[i]][s[i]], len[i]));
		for (int j = 0; j < maxk; ++j)
			sz[j][s[i]] = tmpsz[j][s[i]];
		sz[f[i]][s[i]] = tmpsz[f[i]][s[i]];
	}
	int res = 0;
	for (int i = 0; i < maxk; ++i)
	   res = max (res, sz[i][i]);
	printf ("%d\n", res);
	return 0;
}