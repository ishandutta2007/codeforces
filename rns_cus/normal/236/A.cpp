#include <bits/stdc++.h>
using namespace std;

char s[10001000];
bool vis[111];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i ++) vis[s[i]-'a'] ++;
	int ans = 0;
	for (int i = 0; i < 26; i ++) if (vis[i]) ans ++;
	if (ans & 1) puts("IGNORE HIM!");
	else puts("CHAT WITH HER!");
	return 0;
}