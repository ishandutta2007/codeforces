#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1E4 + 10;
const int MAXM = 1E5 + 10, MAXW = 1E6 + 10, SIGMA = 26;

int n;
char s[MAXN], *f[MAXN];

int m, lent;
char T[MAXW + MAXM];
int cnt, ch[MAXW][SIGMA];
char *mat[MAXW];

int main(){
	scanf("%d%s%d", &n, &s, &m);
	reverse(s, s + n);
	for (int i = 0; i < m; ++i){
		scanf("%s", T + lent);
		int j = 0, u = 0, v;
		for (; T[lent + j]; ++j){
			v = tolower(T[lent + j]) - 'a';
			if (!ch[u][v])
				ch[u][v] = ++cnt;
			u = ch[u][v];
		}
		mat[u] = T + lent;
		lent += j + 1;
	}
	f[0] = T - 1;
	for (int i = 0; i < n; ++i){
		if (!f[i])
			continue;
		int u = 0, v;
		for (int j = i; j < n; ++j){
			v = s[j] - 'a';
			if (!(u = ch[u][v]))
				break;
			if (mat[u])
				f[j + 1] = mat[u];
		}
	}
	for (int flag = 0, i = n; i; i -= strlen(f[i])){
		if (flag)
			putchar(' ');
		flag = true;
		printf("%s", f[i]);
	}
	return 0;
}