#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
int main() {
	scanf("%d", &t);
	while(t--) {
		int n; scanf("%d",&n);
		if(n==1) {
			printf("1\n"); continue;
		}
		int x=1;
		while(x*(x+1)/2 < n) ++x;
		if((x+1)*x/2 - 1 == n) x++;
		printf("%d\n", x);
	}
}