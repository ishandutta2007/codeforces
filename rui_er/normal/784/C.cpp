//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, ma = 0;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &x);
		ma = max(ma, x);
	} 
	printf("%d\n", ma^x);
	return 0;
}