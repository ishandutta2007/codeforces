#include<bits/stdc++.h>
using namespace std;

#define N 110
int n;
char s[N];

int main() {
	scanf("%d%s", &n, s);
	int l = strlen(s);
	int cnt = 0;
	for (int i = 0; i < l; i ++) if (s[i] == '8') cnt ++;
	printf("%d", min(l/11, cnt));
	return 0;
}