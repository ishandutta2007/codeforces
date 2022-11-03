/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 569B
 */
#include <cstdio>
#include <cstring>

const int MAXN = 1E5 + 10;

int a[MAXN];
bool use[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	memset(use, 0, sizeof(use));
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		if (a[i] <= n && !use[a[i]]){
			use[a[i]] = true;
		}
		else{
			a[i] = -a[i];
		}
	}
	for (int j = 1, i = 0; i < n; ++i){
		if (a[i] < 0){
			for (; use[j]; ++j);
			a[i] = j++;
		}
		printf("%d%c", a[i], i < n - 1 ? ' ' : '\n');
	}
	return 0;
}