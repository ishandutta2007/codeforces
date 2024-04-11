#include <bits/stdc++.h>
using namespace std;

char name[60][9], s[9];
int n, k;

void prep() {
	for (int i = 1; i <= 55; i ++) name[i][0] = (i - 1) / 10 + 'A';
	for (int i = 1; i <= 55; i ++) name[i][1] = i % 20 + 'a';
}

void namecopy(int i, int j) {
	name[i][0] = name[j][0];
	name[i][1] = name[j][1];
}

int main() {
	//freopen("9.in", "r", stdin);
	//freopen("9.txt", "w", stdout);
	prep();
	scanf("%d %d\n", &n, &k);
	for (int i = 1; i <= n - k + 1; i ++) {
		scanf("%s", s);
		if (strcmp(s, "NO") == 0) {
			namecopy(i + k - 1, i);
		}
	}
	for (int i = 1; i < n; i ++) printf("%s ", name[i]);
	printf("%s\n", name[n]);
	return 0;
}