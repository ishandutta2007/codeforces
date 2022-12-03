#include <cstdio>
#include <cstring>
using namespace std;

char s[101], t[101];
int a[26];

int main() {
	scanf("%s%s", s, t);
	int j = 0;
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == t[j])
			j++;
	if (j == strlen(t)) {
		printf("automaton\n");
		return 0;
	}
	for (int i = 0; i < strlen(s); i++)
		a[s[i] - 'a']++;
	for (int i = 0; i < strlen(t); i++)
		a[t[i] - 'a']--;
	for (int j = 0; j < 26; j++)
		if (a[j] < 0) {
			printf("need tree\n");
			return 0;
		}
	if (strlen(s) == strlen(t))
		printf("array\n");
	else
		printf("both\n");
	return 0;
}