#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
char s1[30],s2[30],t[1010];
int c[300],n;

int main()
{
	scanf("%s",s1+1);
	rep(i,1,26) c[s1[i]]=i,c[s1[i]-'a'+'A']=i;
	scanf("%s",s2+1);
	scanf("%s",t+1);
	n=strlen(t+1);
	rep(i,1,n)
		if(isdigit(t[i])) printf("%c",t[i]);
		else if(t[i]>='A' && t[i]<='Z') printf("%c",'A'+(s2[c[t[i]]]-'a'));
		else printf("%c",s2[c[t[i]]]);
	puts("");
	return 0;
}