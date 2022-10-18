#include <stdio.h>
#include <vector>
using namespace std;
#define MAXN 200010
int ans[MAXN][30];

int n, m;
char i1[MAXN], i2[MAXN];
char s1[MAXN], s2[MAXN];
int jb[MAXN];

void match(int c1, int c2) {
	for (int i=0; i<n; i++) {
		if (i1[i]-'a' == c1) s1[i] = 1;
		else if (i1[i]-'a' == c2) s1[i] = 2;
		else s1[i] = 0;
	}
	for (int i=0; i<m; i++) {
		if (i2[i]-'a' == c2) s2[i] = 1;
		else if (i2[i]-'a' == c1) s2[i] = 2;
		else s2[i] = 0;
	}
	s2[m] = -1;
	for (int i=2; i<=m; i++) {
		jb[i] = jb[i-1];
		while (1) {
			if (s2[jb[i]] == s2[i-1]) {jb[i]++; break;}
			else if (jb[i] == 0) break;
			else jb[i] = jb[jb[i]];
		}
	}
	int ml = 0;
	for (int i=0; i<n; i++) {
		if (s1[i] == s2[ml]) ml++;
		else if (ml != 0) ml = jb[ml], i--;
		
		if (ml == m) {
			ans[i][c1] = ans[i][c2] = 1;
		}
	}
	return;
}

int main() {
	scanf("%d%d%s%s",&n,&m,i1,i2);
	for (int i=0; i<26; i++) {
		for (int j=i; j<26; j++) match(i, j);
	}
	int a = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<26; j++) ans[i][0] &= ans[i][j];
		if (ans[i][0]) a++;
	}
	printf("%d", a);
	int st = 0;
	for (int i=0; i<n; i++) if (ans[i][0]) {
	
	printf("%c%d", st ? ' ' : '\n', i-m+2); st = 1;}
	puts("");
	return 0;
}