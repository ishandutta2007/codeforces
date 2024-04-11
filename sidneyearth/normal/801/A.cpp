#include <bits/stdc++.h>
using namespace std;
char s[200];
int Count(){
	int n = strlen(s), rnt = 0;
	for(int i = 1; i < n; i++)
		if(s[i] == 'K' && s[i-1] == 'V') rnt++;
	return rnt;
}
int main(){
	scanf("%s", s);
	int n = strlen(s);
	int ans = Count();
	for(int i = 0; i < n; i++){
		if(s[i] == 'V') s[i] = 'K';
		else s[i] = 'V';
		ans = max(ans, Count());
		if(s[i] == 'V') s[i] = 'K';
		else s[i] = 'V';
	}
	printf("%d\n", ans);
	return 0;
}