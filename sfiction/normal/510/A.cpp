/*
ID: Sfiction
OJ: ZOJ
PROB: 510A
*/
#include <cstdio>

void putcn(char chr,int n){
	while (n--)
		putchar(chr);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i){
		if (i&1){
			if (i&2){
				putchar('#');
				putcn('.',m-1);
			}
			else{
				putcn('.',m-1);
				putchar('#');
			}
		}
		else
			putcn('#',m);
		puts("");
	}
	return 0;
}