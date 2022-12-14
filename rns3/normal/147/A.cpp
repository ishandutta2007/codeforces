#include <stdio.h>
#include <string.h>

#define N 20010

char s[N], t[N];
int n;

int main() {
	gets(s);
	n = strlen(s);
	for (int i = 0, j = 0, k; i < n;) {
		if (s[i] == ' ') {
			t[j++] = ' ';
			while (s[i] == ' ') i ++;
			if (s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?') {
				t[j-1] = s[i++];
				t[j++] = ' ';
			}
			while (s[i] == ' ') i ++;
		}
		else if (s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?') {
			t[j++] = s[i++];
			t[j++] = ' ';
			while (s[i] == ' ') i ++;
		}
		else {
			t[j++] = s[i++];
		}
	}
	puts(t);
	return 0;
}