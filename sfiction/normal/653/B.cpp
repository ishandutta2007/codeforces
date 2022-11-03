#include <cstdio>

int n, q;
int a[6][6];
int b[6];

bool solve(){
	for (int i = n - 1; i > 0; --i)
		if (a[b[i]][b[i - 1]] < 0)
			return false;
		else
			b[i - 1] = a[b[i]][b[i - 1]];
	return !b[0];
}

int main(){
	scanf("%d%d", &n, &q);
	char s1[5], s2[5];
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 6; ++j)
			a[i][j] = -1;
	for (int i = 0; i < q; ++i){
		scanf("%s%s", s1, s2);
		a[s1[0] - 'a'][s1[1] - 'a'] = s2[0] - 'a';
	}
	int tot = 1;
	for (int i = 0; i < n; ++i)
		tot *= 6;
	int ans = 0;
	for (int i = 0; i < tot; ++i){
		for (int t = i, j = 0; j < n; ++j)
			b[j] = t % 6, t /= 6;
		ans += solve();
	}
	printf("%d\n", ans);
	return 0;
}