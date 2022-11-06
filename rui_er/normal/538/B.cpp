// LUOGU_RID: 90441005
//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int n, ans, bits, _bits[10];

int main() {
	scanf("%d", &n);
	int _ = n;
	while(_bits[++bits] = _ % 10, _ /= 10);
	reverse(_bits+1, _bits+1+bits);
	for(int i=1;i<=bits;i++) ans = max(ans, _bits[i]);
	printf("%d\n", ans);
	while(ans--) {
		bool __ = false;
		for(int i=1;i<=bits;i++) {
			if(_bits[i]) --_bits[i], putchar(49), __ = true;
			else if(__) putchar(48);
		}
		putchar(32);
	}
	putchar('\n');
	return 0;
}