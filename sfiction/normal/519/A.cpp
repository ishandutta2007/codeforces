/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 519A
 */
#include <cstdio>

const int MAXN = 10;

const int type = 5, w[5] = {9, 5, 3, 3, 1};
const char *chr = "qrbnp";

int n = 8;
char s[MAXN][MAXN];

int main(){
	int white = 0, black = 0;
	for (int i=0;i<n;++i){
		scanf("%s", s[i]);
		for (int j=0;j<n;++j){
			for (int k=0;k<type;++k)
				if (chr[k] == s[i][j])
					black += w[k];
				else if (chr[k] - 'a' + 'A' == s[i][j])
					white += w[k];
		}
	}
	puts(black == white ? "Draw" : black > white ? "Black" : "White");

	return 0;
}