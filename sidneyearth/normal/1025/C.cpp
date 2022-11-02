#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
char s[200100];
int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; i++)
		s[n + i] = s[i];
	int dp = 0, ans = 0;
	for(int i = 1; i <= 2 * n; i++){
		dp = s[i] != s[i-1] ? dp + 1 : 1;
		ans = max(ans, dp);
	}
	printf("%d\n", min(n, ans));
	return 0;
}