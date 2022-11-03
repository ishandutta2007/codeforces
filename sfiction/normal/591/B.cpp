#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2E5 + 10, SIGMA = 26;

char s[MAXN];
char a[26], b[26];

int main(){
	int m;
	scanf("%*d%d%s", &m, s);
	for (int i = 0; i < SIGMA; ++i)
		a[i] = 'a' + i;
	char A, B;
	for (int i = 0; i < m; ++i){
		getchar();
		A = getchar();
		getchar();
		B = getchar();
		swap(a[A - 'a'], a[B - 'a']);
	}
	for (int i = 0; i < SIGMA; ++i)
		b[a[i] - 'a'] = 'a' + i;
	for (char *p = s; *p; ++p)
		putchar(b[*p - 'a']);
	return 0;
}