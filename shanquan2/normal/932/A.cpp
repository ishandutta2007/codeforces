#include<bits/stdc++.h>
using namespace std;

char s[10005];
int main(){
	scanf("%s",s);
	printf("%s",s);
	for(int i=strlen(s)-1;i>=0;i--)printf("%c",s[i]);printf("\n");
	return 0;
}