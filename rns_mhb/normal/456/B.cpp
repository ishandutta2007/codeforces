#include <bits/stdc++.h>
using namespace std;

char s[100005];
int b[5][4] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 4, 8, 1, 3, 4, 2, 1, 4, 1, 4};

int main(){
	scanf("%s", s);
	int len = strlen(s);
	int a = ((int)s[len - 2] * 10 + (int)s[len - 1]) % 4;
	printf("%d", (b[1][a] + b[2][a] + b[3][a] + b[4][a]) % 5);
}