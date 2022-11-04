#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2002;

int t, n, cnt, ans;
char s[N][N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		cnt = 0;
		ans = 0;
		for(int i = 1; i <= n; i++)
			scanf("%s", s[i] + 1);
		for(int i = 1; i <= n; i++){
			int ret = 0;
			for(int j = 0; j < n; j++){
				cnt += (s[i][j + 1] == '1');
				ret += (s[(i + j) % n + 1][j + 1] == '1');
			}
			ans = max(ans, ret);
		}
		printf("%d\n", cnt + n - ans - ans);
	}
	return 0;
}