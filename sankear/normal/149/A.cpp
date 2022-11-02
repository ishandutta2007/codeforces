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

int a[20];

int main(){
	//freopen("tests.in", "r", stdin);
	//freopen("tests.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	scanf("%d", &k);
	for(int i = 0; i < 12; i++){
		scanf("%d", &a[i]);
	}
	int all = (1 << 12), ans = 13;
	for(int i = 0; i < all; i++){
		int sum = 0, sz = 0;
		for(int j = 0; j < 12; j++){
			if((i & (1 << j)) != 0){
				sum += a[j];
				sz++;
			}
		}
		if(sum >= k){
			ans = min(ans, sz);
		}
	}
	if(ans > 12){
		printf("-1\n");
		return 0;
	}
	printf("%d\n", ans);
	return 0;
}