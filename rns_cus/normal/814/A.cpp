#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 100010

int a[N], b[N], n, k;

int main(){

	//freopen("in.txt", "r", stdin);


	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i ++){
		scanf("%d", a + i);
	}
	for(int i = 1; i <= k; i ++){
		scanf("%d", b + i);
	}

	if(k >= 2){
		 puts("Yes"); return 0;
	}

	int cur = 1;

	for(int i = 1; i <= n; i ++){
		if(a[i] == 0){
			a[i] = b[cur ++];
		}
		if(a[i-1] >= a[i]){
			puts("Yes"); return 0;
		}
	}
	puts("No");
}