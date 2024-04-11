//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int n, g;
int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		int _; scanf("%d", &_);
		g = g ? gcd(g, _) : _;
	}
	printf("%d\n", n*g);
	return 0;
}