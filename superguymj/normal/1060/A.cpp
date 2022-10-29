#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,cnt,ans;
char s[10000];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n) if(s[i]=='8') ++cnt;
	rep(i,1,n)
	{
		if(i>cnt) break;
		if(i+i*10>n) break;
		ans=i;
	}
	printf("%d\n",ans);
	return 0;
}