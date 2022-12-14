#include <bits/stdc++.h>

using namespace std;

int read () {
	int x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ? -1 : 1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

const int maxn = 2e5 + 10;

int n , ans;

char s[maxn];

bool vis[maxn];

int main() {
	n = read();
	scanf("%s" , s + 1);
	for (int i = 1 , j , k ; i <= n ; i = k) {
		j = i , k = i + 1;
		if (s[j] == '>' && s[k] == '<') {
			while (s[j] == '>') vis[j --] = 1;
			while (s[k] == '<') vis[k ++] = 1;
		}
	}
	for (int i = 1 ; i <= n ; i ++) ans += 1 - vis[i];
	printf("%d\n" , ans);
	return 0;
}