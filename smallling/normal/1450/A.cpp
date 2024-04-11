#include <bits/stdc++.h>

using namespace std;

char s[220];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		scanf("%s", s + 1);
		for(int i = 1; i <= n; i++)
			if(s[i] == 'b')putchar(s[i]);
		for(int i = 1; i <= n; i++)
			if(s[i] != 'b')putchar(s[i]);
		puts("");
	}
}