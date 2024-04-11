#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 102, inf = 0x7fffffff;

int t, n, ans, cnt;
char s[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		ans = cnt = 0;
		scanf("%d%s", &n, s + 1);
		for(int i = n; i; i--){
			if(s[i] == 'A'){
				ans = max(ans, cnt);
				cnt = 0;
			}else cnt++;
		}
		printf("%d\n", ans);
	}
	return 0;
}