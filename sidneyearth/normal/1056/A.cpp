#include <bits/stdc++.h>
int cnt[110];
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int r; scanf("%d", &r);
		for(int j = 1; j <= r; j++){
			int x; scanf("%d", &x);
			cnt[x]++;
		}
	}
	for(int i = 1; i <= 100; i++)
		if(cnt[i] == n) printf("%d ", i);
	printf("\n");
	return 0;
}