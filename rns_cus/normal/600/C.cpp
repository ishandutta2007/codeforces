#include <bits/stdc++.h>
using namespace std;
#define N 200200

char s[N];
int a[N];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i ++) a[s[i]-'a'] ++;
	int odd = 0;
	for (int i = 0; i < 26; i ++) {
		if (a[i] & 1) odd ++;
	}
	int step = odd / 2;
	while (step) {
		for (int j = 0; j < 26; j ++) if (a[j] & 1) {
			for (int k = 25; k > j; k --) if (a[k] & 1) {
				a[j] ++, a[k] --;
				step --; break;
			}
		}
	}
	if (odd & 1) {
		int mid;
		for (int i = 0; i < 26; i ++) if (a[i] & 1) mid = i, a[i] --;
		for (int i = 0; i < 26; i ++) {
			for (int j = 0; j < a[i] / 2; j ++) printf("%c", 'a' + i);
		}
		printf("%c", 'a' + mid);
		for (int i = 25; i >= 0; i --) {
			for (int j = 0; j < a[i] / 2; j ++) printf("%c", 'a' + i);
		}
		puts("");
	}
	else {
		for (int i = 0; i < 26; i ++) {
			for (int j = 0; j < a[i] / 2; j ++) printf("%c", 'a' + i);
		}
		for (int i = 25; i >= 0; i --) {
			for (int j = 0; j < a[i] / 2; j ++) printf("%c", 'a' + i);
		}
		puts("");
	}
	return 0;
}