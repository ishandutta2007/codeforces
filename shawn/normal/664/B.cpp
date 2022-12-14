#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

struct str{
	char s[maxn];
	int l;
}a;

int n, value, tot, num[maxn];

int main() {
	gets(a.s + 1); 
	a.l = strlen(a.s + 1);
	int i, flag = 1;
	for (i = 1; i <= a.l; i ++) {
		if (a.s[i] == '?') {
			value += flag;
			num[++ tot] = flag;			
		}
		if (a.s[i] == '+') flag = 1;
		if (a.s[i] == '-') flag = -1;
		if (a.s[i] == '=') break;
	}
	int x = 0, f = 1;
	while (a.s[i] > '9' || a.s[i] < '0') f = a.s[i] == '-' ? -1 : 1 , i ++;
	while (a.s[i] >= '0' && a.s[i] <= '9') x = x * 10 + a.s[i] - 48 , i ++;
	n = x * f;
	for (i = 1; i <= tot; i ++) {
		while (value < n && num[i] < n && num[i] > 0) num[i] ++, value ++;
		while (value > n && num[i] > -n && num[i] < 0) num[i] --, value --;
	}
	if (value != n) return puts("Impossible"), 0;
	puts("Possible");
	printf("%d ", num[1]);
	for (i = 2; i <= tot; i ++) {
		if (num[i] > 0) printf("+ %d ", num[i]);
		else printf("- %d ", -num[i]);
	}
	printf("= %d\n", n);
	return 0;
}