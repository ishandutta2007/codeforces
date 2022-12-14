#include <bits/stdc++.h>
using namespace std;
#define N 105

int n, a[N];

int main(){
	int i, j, k, mx;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", a + i);
	k = a[0], mx = a[0];
	for(i = 1; i < n; i++){
		k = __gcd(k, a[i]);
		mx = max(mx, a[i]);
	}
	j = mx / k - n;
	if(j % 2) puts("Alice");
	else puts("Bob");
}