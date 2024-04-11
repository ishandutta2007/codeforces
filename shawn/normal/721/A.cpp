#include <bits/stdc++.h>

using namespace std;

int n , ans[200] , cnt;

char s[200];

int main() {
	scanf("%d" , &n);
	scanf("%s" , s + 1);
	for (int i = 1 ; i <= n ; i ++) {
		if (s[i] == 'B') {
			cnt ++;
			while (s[i] == 'B') ans[cnt] ++ , i ++;
		}
	}
	printf("%d\n" , cnt);
	for (int i = 1 ; i <= cnt; i ++) printf("%d " , ans[i]);
}