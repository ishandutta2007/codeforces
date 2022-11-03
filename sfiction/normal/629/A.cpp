#include <cstdio>

const int MAXN = 1E2 + 10;

int row[MAXN], col[MAXN];
char s[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%s", s);
		for (int j = 0; j < n; ++j){
			row[i] += s[j] == 'C';
			col[j] += s[j] == 'C';
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i){
		ans += row[i] * (row[i] - 1) >> 1;
		ans += col[i] * (col[i] - 1) >> 1;
	}
	printf("%d\n", ans);
	return 0;
}