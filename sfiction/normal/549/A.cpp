/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 549A
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 50 + 5;

char s[MAXN][MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=0;i<n;++i)
		scanf("%s", s[i]);

	int ans = 0;
	char t[10];
	t[4] = 0;
	for (int i=1;i<n;++i)
		for (int j=1;j<m;++j){
			t[0] = s[i - 1][j - 1];
			t[1] = s[i - 1][j];
			t[2] = s[i][j - 1];
			t[3] = s[i][j];
			sort(t, t + 4);
			ans += !strcmp(t, "acef");
		}
	printf("%d", ans);

	return 0;
}