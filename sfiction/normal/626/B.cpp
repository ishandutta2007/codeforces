#include <cstdio>

int main(){
	int n;
	char s[1000];
	scanf("%d%s", &n, s);
	int R = 0, G = 0, B = 0;
	for (int i = 0; i < n; ++i)
		if (s[i] == 'R')
			++R;
		else if (s[i] == 'G')
			++G;
		else
			++B;
	if (R && G && B)
		puts("BGR");
	else if (!R + !G + !B == 1){
		if (R > 1 || G > 1 || !B)
			putchar('B');
		if (R > 1 || !G || B > 1)
			putchar('G');
		if (!R || G > 1 || B > 1)
			putchar('R');
		puts("");
	}
	else
		puts(R ? "R" : G ? "G" : "B");
	return 0;
}