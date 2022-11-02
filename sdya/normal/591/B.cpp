#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

const int maxN = 210000;
char values[26];
char s[maxN];

int main() {
	// your code goes here
	for (int i = 0; i < 26; ++i) {
		values[i] = 'a' + i;
	}
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", &s);
	for (int i = 0; i < m; ++i) {
		char a, b;
		scanf(" %c %c", &a, &b);
		int x, y;
		for (int i = 0; i < 26; ++i) {
			if (values[i] == a) {
				x = i;
			}
			if (values[i] == b) {
				y = i;
			}
		}
		swap(values[x], values[y]);
	}
	for (int i = 0; i < n; ++i) {
		s[i] = values[s[i] - 'a'];
	}
	puts(s);
	return 0;
}