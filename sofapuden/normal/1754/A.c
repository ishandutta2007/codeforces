#include<stdio.h>
#define MX	105

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		char s[MX];
		scanf("%s", s);
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			cnt += s[i] == 'Q';
			cnt -= s[i] == 'A';
			cnt += cnt < 0;
		}
		if(cnt){
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
}