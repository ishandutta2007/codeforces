#include <bits/stdc++.h>
using namespace std;

int n, k;
char s[300300];

int main() {
	scanf("%d %d\n", &n, &k);
	gets(s);
	for(int i = 0; i < n; i ++) {
		if(k <= 0) break;
		if(s[i] - 'a' > 'z' - s[i]) {
			while(s[i] != 'a' && k --) s[i] --;
		} else {
			while(s[i] != 'z' && k --) s[i] ++;
		}
	}
	if(k > 0) puts("-1"); else puts(s);
	return 0;
}