#include <stdio.h>
int a[20];
int f(int st, int n){
	int rnt = 0;
	for(int i = 0; i < n; i++)
		rnt += a[i] * ((st >> i & 1) ? 1 : -1);
	return rnt % 360 == 0;
}
int main(){
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	bool ans = false;
	for(int st = 0; st < (1 << n); st++)
		if(f(st, n)){
			ans = true;
			break;
		}
	printf("%s\n", ans ? "YES" : "NO");
	return 0;
}