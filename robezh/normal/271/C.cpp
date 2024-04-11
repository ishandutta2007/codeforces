#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int n,k;
	scanf("%d%d", &n, &k);
	if(n < k * 3) return !printf("-1");
	for(int i = 1; i <= n; i++){
		if((i-1) / k == 2) printf("%d ", i % k + 1);
		else printf("%d ", (i - 1) % k + 1);
	}
}