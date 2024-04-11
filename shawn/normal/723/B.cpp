#include <bits/stdc++.h>

using namespace std;

int read () {
	int x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ?-1 :1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

char s[400];
int n , tmp , len , num;

int main() {
	n = read();
	scanf("%s" , s + 1);
	for (int i = 1 ; i <= n ; i ++) {
		if (s[i] == '_') {
			tmp = 0;
			continue;
		}
		if (s[i] == '(') {
			while (s[i] != ')') {
				i ++;
				if (s[i] == ')') {
					i ++;
					break;
				}
				if (s[i] != '_') {
					num ++;
					while (s[i] != '_' && s[i] != ')' && i <= n) i ++;
					i --;
				}
			}
			i --;
		} else {
			while (s[i] != '_' && s[i] != '(' && i <= n) tmp ++ , i ++;
			i --;
			len = max(tmp , len);
			tmp = 0;
		}
	}
	printf("%d %d\n" , len , num);
	return 0;
}