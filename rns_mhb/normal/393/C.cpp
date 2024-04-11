#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	if (!n) puts("1");
	else printf("%d", 4 * ((int)(sqrt(2) * n)));
}