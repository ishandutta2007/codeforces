#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

int ans[110];

int main(){
    //freopen("rifleman.in", "r", stdin);
    //freopen("rifleman.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	if(b == 0){
		if(a > 0 && n == a + 1){
			printf("-1\n");
			return 0;
		}
		ans[1] = 1;
		ans[2] = 1;
		for(int i = 3; i <= a + 2; i++){
			ans[i] = ans[i - 1] + 1;
		}
		for(int i = a + 3; i <= n; i++){
			ans[i] = 1;
		}
		for(int i = 1; i <= n; i++){
			if(i > 1){
				printf(" ");
			}
			printf("%d", ans[i]);
		}
		printf("\n");
		return 0;
	}
	ans[1] = 1;
	for(int i = 2; i <= b + 1; i++){
		ans[i] = ans[i - 1] * 2;
	}
	for(int i = b + 2; i <= b + a + 1; i++){
		ans[i] = ans[i - 1] + 1;
	}
	for(int i = b + a + 2; i <= n; i++){
		ans[i] = 1;
	}
	for(int i = 1; i <= n; i++){
		if(i > 1){
			printf(" ");
		}
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}