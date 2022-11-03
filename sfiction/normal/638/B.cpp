#include <cstdio>
#include <cstring>

const int MAXN = 26;

int rec[MAXN];
int nex[MAXN], pre[MAXN];
char s[MAXN + 1];

int main(){
	int n;
	scanf("%d", &n);
	memset(nex, -1, sizeof(nex));
	memset(pre, -1, sizeof(pre));
	for (int i = 0; i < n; ++i){
		scanf("%s", s);
		rec[s[0] - 'a'] = true;
		for (int j = 1; s[j]; ++j){
			rec[s[j] - 'a'] = true;
			nex[s[j - 1] - 'a'] = s[j] - 'a';
			pre[s[j] - 'a'] = s[j - 1] - 'a';
		}
	}
	int r = 0;
	char ans[MAXN + 1];
	for (int i = 0; i < MAXN; ++i)
		if (rec[i]){
			int u = i;
			for (; ~pre[u]; u = pre[u]);
			ans[r++] = u + 'a';
			rec[u] = false;
			for (u = nex[u]; ~u; u = nex[u]){
				ans[r++] = u + 'a';
				rec[u] = false;
			}
		}
	ans[r] = '\0';
	puts(ans);
	return 0;
}