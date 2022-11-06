//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int n, x, ma, gc; 

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", &x);
		ma = i == 1 ? x : max(ma, x);
		gc = i == 1 ? x : __gcd(gc, x);
	}
	int re = ma / gc - n;
	puts(re&1?"Alice":"Bob");
	return 0;
}