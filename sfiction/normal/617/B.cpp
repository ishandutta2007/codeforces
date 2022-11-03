#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	long long ans = 1;
	int pre = -1;
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		if (t){
			if (~pre)
				ans *= i - pre;
			pre = i;
		}
	}
	printf("%I64d\n", ~pre ? ans : 0);
	return 0;
}