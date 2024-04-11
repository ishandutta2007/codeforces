#include <bits/stdc++.h>
using namespace std;

#define N 1000010

int n, k, num, cnt[30];
char s[N];
bool vis[30], flag;

int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < n; i ++) cnt[s[i] - 'A'] ++;
	for (int i = 0; i < n; i ++) {
		if (!vis[s[i] - 'A']) num ++;
		vis[s[i] - 'A'] = 1;
		cnt[s[i] - 'A'] --;
		if (num > k) {
			puts("YES");
			return 0;
		}
		if (!cnt[s[i] - 'A']) num --;
		
	}
	puts("NO");
}