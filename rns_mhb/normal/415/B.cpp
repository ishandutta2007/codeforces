#include <bits/stdc++.h>
using namespace std;

int main(){
	int i, j, n, a, b, x;
	long long y;
	scanf("%d %d %d", &n, &a, &b);
	while(n--){
		scanf("%d", &x);
		y = 1ll * x * a / b;
		printf("%d ", (int)(x - (1ll * b * y + a - 1) / a));
	}
}