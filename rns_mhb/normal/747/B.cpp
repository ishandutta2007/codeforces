#include <bits/stdc++.h>
using namespace std;

char s[100100], ss[100100];
int n, A, C, G, T, rep[100100];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %s", &n, s);
	int cnt = 0;
	if (n % 4) {
		puts("==="); return 0;
	}
	for (int i = 0; i < n; i ++) {
		if (s[i] == 'A') A ++;
		else if (s[i] == 'C') C ++;
		else if (s[i] == 'G') G ++;
		else if (s[i] == 'T') T ++;
		else rep[cnt++] = i;
	}
	if (A > n / 4 || C > n / 4 || G > n / 4 || T > n / 4) {
		puts("==="); return 0;
	}
	int runs = 0;
	for (int i = A + 1; i <= n / 4; i ++) ss[runs++] = 'A';
	for (int i = C + 1; i <= n / 4; i ++) ss[runs++] = 'C';
	for (int i = G + 1; i <= n / 4; i ++) ss[runs++] = 'G';
	for (int i = T + 1; i <= n / 4; i ++) ss[runs++] = 'T';
	for (int i = 0; i < cnt; i ++) s[rep[i]] = ss[i];
	puts(s);
	return 0;
}