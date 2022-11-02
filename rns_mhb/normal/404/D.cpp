#include<stdio.h>
#include<string.h>
#define M 1000001
const int c = 1000000007;

char s[M];
__int64 f[2],g[2],ff;
int l;

bool check(int r){
	int a=0,b=0;
	if(r){
		if(s[r-1]=='*'){a++;b++;}
		if(s[r-1]=='?')b++;
	}
	if(r<l-1){
		if(s[r+1]=='*'){a++;b++;}
		if(s[r+1]=='?')b++;
	}
	return (s[r]-'0'>b || s[r]-'0'<a);
}

int main(){

	//freopen("in.txt","r",stdin);

	int i;

	gets(s);
	l=strlen(s);
	for(i=0;s[i];i++)if(s[i]!='?' && s[i]!='*'){
		if(check(i))return puts("0");
	}
	ff=1ll;
	for(i=0;i<l;i++)if(s[i]=='?'){
		s[i]='*';g[1]=0;
		if(i<l-1 && s[i+1]!='?' && s[i+1]!='*' && check(i+1))goto aa;
		if(i && s[i-1]!='?' && s[i-1]!='*' && check(i-1))goto aa;
		g[1]=ff;
		if(i>1){
			if(s[i-1]=='1' && s[i-2]=='?')g[1]=f[0];
			else if(s[i-1]=='2' && s[i-2]=='?')g[1]=f[1];
		}
	aa:	s[i]='0';g[0]=0;
		if(i<l-1 && s[i+1]!='?' && s[i+1]!='*' && check(i+1))goto bb;
		if(i && s[i-1]!='?' && s[i-1]!='*' && check(i-1))goto bb;
		g[0]=ff;
		if(i>1){
			if(s[i-1]=='0' && s[i-2]=='?')g[0]=f[0];
			else if(s[i-1]=='1' && s[i-2]=='?')g[0]=f[1];
		}
	bb:	f[0]=g[0];f[1]=g[1];ff=f[0]+f[1];
		if(ff>c)ff%=c;
		s[i]='?';
	}
	printf("%I64d\n",ff);
	return 0;
}