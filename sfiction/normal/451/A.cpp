/*
ID: Sfiction
OJ: CF
PROB: 451A
*/
#include <cstdio>

int main(){
	int n, m;

	scanf("%d%d",&n,&m);
	puts((n < m ? n : m) & 1 ? "Akshat" : "Malvika");

	return 0;
}