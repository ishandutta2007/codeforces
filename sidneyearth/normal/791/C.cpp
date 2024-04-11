#include<cstdio>
const int maxn = 110;
int f[maxn];
char s[maxn];
int main(){
	int n, k, cnt = 0;
	scanf("%d%d", &n, &k);
	for(int i = 1; i < k; i++)
		f[i] = ++cnt;
	for(int i = k; i <= n; i++){
		scanf("%s", s);
		if(s[0] == 'N') f[i] = f[i-k+1];
		else f[i] = ++cnt;
	}
	for(int i = 1; i <= n; i++)
		printf("%c%c ", f[i] % 26 + 'A', f[i] / 26 + 'a');
	printf("\n");
	return 0;
}