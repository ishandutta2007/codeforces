#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
char s[maxn];
int f[maxn];
int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; i++)
		f[i] = f[i-1] + (s[i] == 'a');
	int ans = 0;
	for(int i = 0; i <= n; i++)
		for(int j = i; j <= n; j++){
//			printf("i:%d j:%d %d\n", i, j, f[i] + j - i - f[j] + f[i] + f[n] - f[j]);
			ans = max(ans, f[i] + j - i - f[j] + f[i] + f[n] - f[j]);
		}
	printf("%d\n", ans);
	return 0;
}