#include <bits/stdc++.h>
using namespace std;
char s[100];
int main() {
	//freopen("in.txt", "r", stdin);
	int x, y;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", s, &x, &y);
		if (x >= 2400 && y > x) {
			return puts("YES"), 0;
		}
	}
	return puts("NO"), 0;
}