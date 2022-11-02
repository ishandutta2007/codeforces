#include <bits/stdc++.h>
using namespace std;

int n;
char s[300300];

int main() {
	gets(s);
	n = strlen(s);
	long long ans = 0;
	for(int i = 0; i < n; i ++) {
		if((s[i]-'0') % 4 == 0) ans ++;
		if(i && ((s[i-1]-'0')*10 + (s[i]-'0')) % 4 == 0) ans += i;
	}
	printf("%I64d\n", ans);
	return 0;
}