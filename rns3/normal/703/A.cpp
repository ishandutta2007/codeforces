#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int a = 0, b = 0;
	for(int i = 1; i <= n; i ++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if(x > y) a ++;
		else if(x < y) b ++;
	}
	if(a > b) puts("Mishka");
	else if(a < b) puts("Chris");
	else puts("Friendship is magic!^^");
}