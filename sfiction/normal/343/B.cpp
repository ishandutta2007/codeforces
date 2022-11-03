/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 343B
 */
#include <cstdio>
#include <cstring>

const int MAXN = 1E5 + 100;

int n;
char s[MAXN];

int r;
char sta[MAXN];

int main(){
	scanf("%s", s);

	r = -1;
	for (int i=0;s[i];++i)
		if (r >= 0 && s[i] == sta[r])
			--r;
		else
			sta[++r] = s[i];

	puts(!~r ? "Yes" : "No");

	return 0;
}