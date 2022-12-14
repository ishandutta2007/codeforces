#include <bits/stdc++.h>
using namespace std;

int main() {
	///freopen("1.in", "r", stdin);
	long long n;
    scanf("%I64d", &n);
    long long sum = 0;
    for(int i = 1; ; i ++) {
		if(sum + i >= n) {
			printf("%I64d\n", n - sum);
			exit(0);
		}
		sum += i;
    }

}