/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 443A
 */
#include <cctype>
#include <cstdio>
#include <cstring>

const int MAXN = 26;

bool vis[MAXN];

int main(){
	char c;

	memset(vis, 0, sizeof(vis));
	while ((c = getchar()) != EOF)
		if (islower(c))
			vis[c - 'a'] = true;

	int ret = 0;
	for (int i=0;i<26;++i)
		ret += vis[i];
	printf("%d", ret);

	return 0;
}