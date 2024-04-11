#include <stdio.h>
#include <vector>

int main() {
	int h, i, j;
	int t;
	char s[50];
	int count[26];
	int one, two;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%s", &s);
		one = 0;
		two = 0;
		for(i=0; i<26; i++) {
			count[i] = 0;
		}
		for(i=0; s[i]; i++) {
			count[s[i]-'a']++;
		}
		for(i=0; i<26; i++) {
			if(count[i] == 1) {
				one++;
			} else if(count[i] >= 2) {
				two++;
			}
		}
		printf("%d\n", two+one/2);
	}
}