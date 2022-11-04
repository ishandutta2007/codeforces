#include <cstdio>
using namespace std;

int t, n, k;
char board[41][41];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		if(k > (n - 1) / 2 + 1){
			puts("-1");
			continue;
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				board[i][j] = '.';
		for(int i = 0; i < k; i++)
			board[i * 2][i * 2] = 'R';
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				putchar(board[i][j]);
			putchar('\n');
		}
	}
	return 0;
}