//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

char s[105];
int len, neg, dot;
int find_dot(char *ss) {
	int l = strlen(ss);
	rep(i, 0, l-1) if(ss[i] == '.') return i;
	return l;
}

int main() {
	scanf("%s", s);
	neg = s[0] == '-';
	if(neg) {strcpy(s, s+1); putchar('(');}
	putchar('$'); len = strlen(s);
	dot = find_dot(s);
	rep(i, 0, dot-1) {
		if(i && (dot - i) % 3 == 0) putchar(',');
		putchar(s[i]);
	}
	putchar('.');
	if(dot != len) {
		putchar(s[dot+1]);
		int qwq = len - 1 - dot;
		if(qwq == 1) putchar('0');
		else putchar(s[dot+2]);
	}
	else {putchar('0'); putchar('0');}
	if(neg) putchar(')');
	putchar('\n');
	return 0;
}