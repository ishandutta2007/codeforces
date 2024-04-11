#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == b+c || b == a+c || c == a+b || (a==b && c%2==0) || (a==c && b%2==0) || (b==c && a%2==0)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}