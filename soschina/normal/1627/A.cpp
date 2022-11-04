#include <cstdio>
#include <iostream>
using namespace std;

int t, n, m, r, c;
int ans;
bool allwhite;
char ch;

int main(){
	scanf("%d", &t);
	while(t--){
		allwhite = true;
		ans = 2;
		scanf("%d%d%d%d", &n, &m, &r, &c);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++){
				scanf(" %c", &ch);
				if(ch == 'B'){
					allwhite = false;
					if(i == r && j == c) ans = 0;
					else if(i == r || j == c) ans = min(ans, 1);
				}
			}
		printf("%d\n", allwhite ? -1 : ans);
	}
	return 0;
}