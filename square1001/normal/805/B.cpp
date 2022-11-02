#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) putchar('a' + i % 4 / 2);
	return 0;
}