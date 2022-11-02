#include <bits/stdc++.h>
using namespace std;

int n, a[105], d, mx;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%d", &a[i]);
		if(mx < a[i])	mx = a[i];
	}
	int d = __gcd(a[0], a[1]);
	for(int i = 2; i < n; i ++)	d = __gcd(d, a[i]);
	printf("%s", (mx / d - n) & 1 ? "Alice" : "Bob");
}