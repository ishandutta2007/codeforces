///	B : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;
#define N 250
#define STEP 7

int n, k;
char s[STEP][N][N];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i ++) scanf("%s", s[1][i]);
	for (int d = 2; d <= k; d ++) {
		int len = strlen(s[d-1][0]);
		for (int I = 0; I < len; I ++) {
			for (int J = 0; J < len; J ++) {
				for (int i = 0; i < n; i ++) {
					for (int j = 0; j < n; j ++)
						s[d][I*n+i][J*n+j] = s[d-1][I][J] == '*' ? '*' : s[1][i][j];
				}
			}
		}
	}
	int len = strlen(s[k][0]);
	for (int i = 0; i < len; i ++) puts(s[k][i]);
	return 0;
}