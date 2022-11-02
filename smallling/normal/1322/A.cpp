#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

char s[N];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	int cnt = 0, last = 0, ans = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '(')cnt++;
		else cnt--;
		if(cnt < 0 && last == 0)last = i;
		if(cnt >= 0 && last != 0)ans += i - last + 1, last = 0;
	}
	if(cnt != 0)puts("-1");
	else printf("%d\n", ans);
}