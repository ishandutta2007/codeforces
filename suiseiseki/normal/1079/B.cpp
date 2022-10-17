#include <cstdio>
char s[105];
int main(){
	int n=0;
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	int row,line;
	row=(n+19)/20;
	line=(n+row-1)/row;
	printf("%d %d\n",row,line);
	for(int i=1,num=1;i<=n;num++){
		if(row*line-n>=num){
			putchar('*');
			for(int j=1;j<line;j++){
				putchar(s[i+j-1]);
			}
			i+=line-1;
		}
		else{
			for(int j=1;j<=line;j++){
				putchar(s[i+j-1]);
			}
			i+=line;
		}
		puts("");
	}
	return 0;
}