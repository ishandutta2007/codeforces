#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	char s[2][5] = {"love", "hate"};
	scanf("%d", &n);
	for (int i = 1; i < n; i ++) printf("I %s that ", s[i%2]);
	printf("I %s it", s[n%2]);
	return 0;
}