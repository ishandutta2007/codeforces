#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int array[3000000];
int l, r;
int n;
char s[2000000];

int main () {
	scanf ("%s", s);
	n = strlen(s);
	l = 1000000;
	r = 999999;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == 'l')
			array[++r] = i + 1;
		else
			array[--l] = i + 1;
	}
	for (int i = l; i <= r; ++i)
		printf ("%d\n", array[i]);
	return 0;
}