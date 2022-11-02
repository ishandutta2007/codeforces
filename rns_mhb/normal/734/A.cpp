#include<bits/stdc++.h>
using namespace std;

char str[101000];
int n, cnt;
main(){
	scanf("%d\n",&n);
	gets(str);
	for(int i = 0;i < n;i ++) if(str[i] == 'A') cnt ++;
	if(2 * cnt > n) puts("Anton");
	else if(2 *  cnt == n) puts("Friendship");
	else puts("Danik");
}