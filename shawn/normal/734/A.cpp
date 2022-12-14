#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
} 

char s[100010];
int A, D, l;

int main() {
	l = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= l; i ++) {
		if (s[i] == 'D') D ++;
		else A ++;
	}
	if (A > D) puts("Anton");
	else if (D > A) puts("Danik");
	else puts("Friendship");
	return 0;
}