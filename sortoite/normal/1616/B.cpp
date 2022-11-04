#include<bits/stdc++.h>
using namespace std;
char s[100010];
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		int n; scanf("%d %s", &n, s);
		if(n == 1 || s[0] <= s[1]) {
			printf("%c%c\n", s[0], s[0]);
			continue;
		}
		int k = n;
		for(int i = 1; i < n; i ++) {
			if(s[i - 1] < s[i]) {
				k = i;
				break;
			}
		}
		s[k] = 0;
		printf("%s", s);
		reverse(s, s + k);
		printf("%s\n", s);
	}
	return 0;
}