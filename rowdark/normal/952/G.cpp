#include<stdio.h>
char s[3][2000];
char rd[11];
unsigned char now=0;
int main(){
	scanf("%s",rd);
	for(int i=0;rd[i];++i){
		for(int i=0;i<=1000;++i) s[0][i]=s[1][i]=s[2][i]='.';
		s[1][0]='X';
		s[0][0]='X';
		printf("%s\n",s[2]);
		--now;
		for(int j=2;j<=1000;j+=2){
			if(now!=(unsigned char)rd[i]) --now,s[0][j]='X';
			else break;
		}
		printf("%s\n",s[0]);
		printf("%s\n",s[1]);
	}
	return 0;
}