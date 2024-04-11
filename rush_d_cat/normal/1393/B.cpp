#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int n, a[N], q, x, C[N];
char s[2];
int cnt = 0, A = 0;

void add(int x) {
	C[x] ++;
	if (C[x] % 2 == 0) cnt ++;
	if (C[x] == 4) A ++;
}
void del(int x) {
	C[x] --;
	if (C[x] % 2 == 1) cnt --;
	if (C[x] == 3) A --;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]); add(a[i]);
	}
	scanf("%d", &q);
	while (q --) {
		scanf("%s%d", s, &x);
		if (s[0] == '+') {
			add(x);
		}else{
			del(x);
		}
		if(A>=1 && cnt >= 4) printf("YES\n");
		else printf("NO\n");
	}
}