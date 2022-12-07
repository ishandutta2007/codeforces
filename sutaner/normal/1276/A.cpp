#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200019
using namespace std;

char s[maxn];
bool vis[maxn];

int main(){
	int T, n;
	scanf("%d", &T);
	while (T--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		rep(i, 1, n - 4) if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e') vis[i + 2] = 1;
		rep(i, 1, n - 2) if (!vis[i] && !vis[i + 1] && !vis[i + 2] && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') vis[i + 1] = 1;
		rep(i, 1, n - 2) if (!vis[i] && !vis[i + 1] && !vis[i + 2] && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') vis[i + 1] = 1;
		int ans = 0;
		rep(i, 1, n) if (vis[i]) ans++;
		printf("%d\n", ans);
		rep(i, 1, n) if (vis[i]) vis[i] = 0, printf("%d ", i); printf("\n");
	}
	return 0;
}