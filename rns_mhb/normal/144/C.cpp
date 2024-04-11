#include <bits/stdc++.h>
using namespace std;

#define N 100010

char s[N], p[N];

int a[30], b[30];

bool check() {
	for (int i = 0; i < 26; i ++) if (a[i] > b[i]) return 0;
	return 1;
}

int main() {
	scanf("%s%s", s, p);
	int n = strlen(s);
	int m = strlen(p);
	int ans;
	if (m <= n) {
		for (int i = 0; i < m; i ++) b[p[i]-'a'] ++;
		for (int i = 0; i < m; i ++) if (s[i] != '?') a[s[i]-'a'] ++;
		ans = check();
		for (int i = m; i < n; i ++) {
			if (s[i] != '?') a[s[i]-'a'] ++;
			if (s[i-m] != '?') a[s[i-m]-'a'] --;
			ans += check();
		}
	}
	else ans = 0;
	cout<<ans<<endl;
}