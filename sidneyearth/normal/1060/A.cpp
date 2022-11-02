#include <stdio.h>
#include <algorithm>
using namespace std;
char s[1010];
int main(){
	int n; scanf("%d", &n);
	scanf("%s", s);
	int cnt = 0;
	for(int i = 0; i < n; i++)
		cnt += s[i] == '8';
	printf("%d\n", min(cnt, n / 11)); 
	return 0;
}