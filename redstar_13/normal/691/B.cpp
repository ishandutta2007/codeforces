#include <bits/stdc++.h>

using namespace std;

int ok(char a, char b) {
	if (a=='A' && b=='A') return 1;	
	if (a=='b' && b=='d') return 1;
	if (a=='d' && b=='b') return 1;
	if (a=='H' && b=='H') return 1;
	if (a=='I' && b=='I') return 1;
	if (a=='M' && b=='M') return 1;
	if (a=='O' && b=='O') return 1;
	if (a=='o' && b=='o') return 1;
	if (a=='p' && b=='q') return 1;
	if (a=='q' && b=='p') return 1;
	if (a=='T' && b=='T') return 1;
	if (a=='U' && b=='U') return 1;
	if (a=='V' && b=='V') return 1;
	if (a=='v' && b=='v') return 1;
	
	if (a=='W' && b=='W') return 1;
	if (a=='w' && b=='w') return 1;
	if (a=='X' && b=='X') return 1;
	if (a=='x' && b=='x') return 1;
	if (a=='Y' && b=='Y') return 1;
	return 0;
}

int main() {
	
	char s[1111];
	int i, len, yes;
	scanf("%s", s);
	len=strlen(s);
	yes=1;
	
	for (i=0; i<len; i++) {
		if (!ok(s[i], s[len-1-i])) yes=0;
	}
	
	if (yes) puts("TAK");
	else puts("NIE");
	
	return 0; 
}