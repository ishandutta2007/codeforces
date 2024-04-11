#include <stdio.h>
#include <string.h>
#define N 11

char s[N][N];

main() {
    //freopen("a.in", "r", stdin);
    for(int i=0; i<8; i++){
        scanf("%s", s[i]);
    }

	int rlt = 0;
	for (int i = 0; i < 8; i ++) {
		if(strcmp(s[i], "BBBBBBBB") == 0) rlt ++;
	}
	if(rlt == 8) {puts("8"); return 0;}
	for(int j=0; j<8; j++){
		bool fg = 1;
		for(int i=0; i<8; i++) if(s[i][j] == 'W') fg = 0;
		if(fg) rlt ++;
	}
	printf("%d\n", rlt);
}