#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000000 + 10;
int t;
char s[N];
int pre[N][2];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s + 1);
		int q; scanf("%d", &q);
		int n = strlen(s+1);
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < 2; j ++) pre[i][j] = pre[i-1][j];
			if (s[i] == '(' || s[i] == ')') {
				pre[i][i%2] ++;
			} 
		}
		while (q --) {
			int l, r;
			scanf("%d%d",&l,&r);
			printf("%d\n",abs( (pre[r][0]-pre[l-1][0]) - (pre[r][1]-pre[l-1][1]) ));
		}
	}
}