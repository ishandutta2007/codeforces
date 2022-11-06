//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int win[3][3] = {
	{0, 1, 0}, 
	{0, 0, 1}, 
	{1, 0, 0}
};

int a, b, c; 
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
int read() {
	char s[15];
	scanf("%s", s);
	if(s[0] == 'r') return 0;
	if(s[0] == 's') return 1;
	return 2;
}

int main() {
	a = read(); b = read(); c = read();
	if(win[a][b] && win[a][c]) puts("F");
	else if(win[b][a] && win[b][c]) puts("M");
	else if(win[c][a] && win[c][b]) puts("S");
	else puts("?");
	return 0;
}