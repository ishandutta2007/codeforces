#include <bits/stdc++.h>
using namespace std;

#define N 3030

typedef pair <int, int> pii;

map <pii, int> mp;
map <pii, int> :: iterator it;

pii now;

char s[N];

int main() {
	int n;
	scanf("%d\n", &n);
	gets(s);
	//int n = strlen(s);
	now = make_pair(0, 0);
	mp[now] ++;
	for (int i = 0; i < n; i ++) {
		if (s[i] == 'U') now.first ++;
		else if (s[i] == 'D') now.first --;
		else if (s[i] == 'L') now.second ++;
		else now.second --;
		mp[now] ++;
	}
	int ans = 0;
	for (it = mp.begin(); it != mp.end(); it ++) {
		ans += (it -> second) * ((it -> second) - 1) / 2;
	}
	printf("%d\n", ans);
	return 0;
}