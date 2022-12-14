#include <bits/stdc++.h>
using namespace std;

#define N 400

char s[N];

int n;

int main() {
	scanf("%d\n", &n);
	gets(s);
	for (int i = 0; i < n; i ++) {
		if (i < n - 2 && s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o') {
            int j = i + 2;
            while (j < n - 2 && s[j+1] == 'g' && s[j+2] == 'o') j += 2;
            printf("***");
            i = j;
		}
		else printf("%c", s[i]);
	}
	return 0;
}