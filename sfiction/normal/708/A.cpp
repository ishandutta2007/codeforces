#include <bits/stdc++.h>

using namespace std;
using namespace placeholders;

const int MAXN = 1E5 + 10;

char s[MAXN];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	char *l = find_if_not(s, s + n, bind(equal_to<char>(), _1, 'a'));
	char *r = find(l, s + n, 'a');
	transform(l, r, l, bind(minus<char>(), _1, 1));
	if (l == r)
		s[n - 1] += 'z' - 'a';
	puts(s);
	return 0;
}