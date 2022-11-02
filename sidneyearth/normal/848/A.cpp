#include <stdio.h>
#include <algorithm>
using namespace std;
int Solve(int n){
	int l = 0, r = 1000;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(mid * (mid - 1) / 2 <= n) l = mid;
		else r = mid;
	}
	return l;
}
int main(){
	int k; scanf("%d", &k);
	if(k == 0) printf("a\n");
	else{
		for(int i = 0, t; i < 26 && k; i++, k -= t * (t - 1) / 2){
			t = Solve(k);
			for(int j = 0; j < t; j++)
				printf("%c", 'a' + i);
		}
		printf("\n");
	}
	return 0;
}