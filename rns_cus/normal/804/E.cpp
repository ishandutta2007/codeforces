#include<bits/stdc++.h>
using namespace std;

#define N 100010

int n;
int a[N];

int main(){
//	freopen("e.out", "w", stdout);
	scanf("%d", &n);
	if((n % 4 == 2) || (n % 4 == 3)){ puts("NO"); return 0; }
	puts("YES");
	while(n >= 4){
		int a = n, b = n - 1, c = n - 2, d = n - 3;
		for(int i = 1; i <= n - 4; i ++){
			printf("%d %d\n", i, a);
		}
		printf("%d %d\n", b, a);
		for(int i = n - 4; i >= 1; i --){
			printf("%d %d\n", i, b);
		}
		for(int i = 1; i <= n - 4; i ++){
			printf("%d %d\n", i, c);
		}
		printf("%d %d\n", d, c);
		for(int i = n - 4; i >= 1; i --){
			printf("%d %d\n", i, d);
		}
		printf("%d %d\n", d, a);
		printf("%d %d\n", c, b);
		printf("%d %d\n", c, a);
		printf("%d %d\n", d, b);
		n -= 4;
	}
}