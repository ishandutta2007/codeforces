#include<bits/stdc++.h>
using namespace std;
int n;
char ch[100005];
int main(){
	scanf("%d%s",&n,ch);
	int ln=strlen(ch),cnt=0;
	for(int i=0;i<ln;++i){
		if(ch[i]=='z')cnt++;
	}
	for(int i=1;i<=(ln-cnt*4)/3;++i)printf("1 ");
	for(int i=1;i<=cnt;++i)printf("0 ");
	return 0;
}