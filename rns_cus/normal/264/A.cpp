#include <bits/stdc++.h>

using namespace std;

#define N 1001000

char s[N];
int pr[N], nx[N], n;

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%s", s);
	n = strlen(s);
	nx[0] = 1; nx[1] = n + 1; pr[n + 1] = 1;
	for(int i = 0; i < n - 1; i ++) {
		int j = i + 1, k = i + 2;
		if(s[i] == 'l') {
			nx[pr[j]] = k;
			pr[k] = pr[j];
            pr[j] = k; nx[k] = j;
		} else {
			nx[k] = nx[j]; pr[nx[j]] = k;
			nx[j] = k; pr[k] = j;
		}
	}
	int cur = 0;
	for(int i = 0; i < n; i ++) {
		cur = nx[cur];
		printf("%d\n", cur);
	}
	return 0;
}