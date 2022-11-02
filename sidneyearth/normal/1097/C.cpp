#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 500010;
const int inf = 0x3f3f3f3f;
int c[2][maxn];
char s[maxn];
int f(){
	int left = 0, right = 0;
	for(int i = 0; s[i]; i++){
		if(s[i] == '(') right++;
		else if(right) right--;
		else left++;
	}
	return left && right ? inf : (left ? -left : right);
}
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%s", s);
		int t = f();
		if(t == inf) continue;
		if(t >= 0) c[0][t]++;
		else c[1][-t]++;
	}
	int ans = 0;
	for(int i = 1; i < maxn; i++)
		if(c[0][i] && c[1][i])
			ans += min(c[0][i], c[1][i]);
	ans += c[0][0] / 2;
	printf("%d\n", ans);
	return 0;
}