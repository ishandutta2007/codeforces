#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,ans;
char s[100];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	rep(i,1,n)
		if(s[i]=='a' || s[i]=='e' || s[i]=='u' || s[i]=='i' || s[i]=='o' || s[i]=='1' || s[i]=='3' || s[i]=='5' || s[i]=='7' || s[i]=='9') ++ans;
	printf("%d\n",ans);
}