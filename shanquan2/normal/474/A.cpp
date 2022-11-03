#include<cstdio>
#include<cstring>
using namespace std;

const char s[40]="qwertyuiopasdfghjkl;zxcvbnm,./";
int main(){
	char x[3];scanf("%s",x);
	char ch[201];scanf("%s",ch);
	int l=strlen(ch);
	for(int i=0;i<l;i++){
		int j=0;
		while(s[j]!=ch[i])j++;
		if(x[0]=='L')printf("%c",s[j+1]);else printf("%c",s[j-1]);
	}
	printf("\n");
	return 0;
}