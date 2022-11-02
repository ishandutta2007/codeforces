#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		char s[20]; scanf("%s", s);
		if(s[0] == 'T') ans += 4;
		else if(s[0] == 'C') ans += 6;
		else if(s[0] == 'O') ans += 8;
		else if(s[0] == 'D') ans += 12;
		else ans += 20;
	}
	printf("%d\n", ans);
	return 0;
}