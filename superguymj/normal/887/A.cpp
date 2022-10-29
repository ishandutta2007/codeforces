#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
char s[105];
int n;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

bool check()
{
	int rt=0;
	rep(i,1,n)
		if(s[i]=='1')
		{
			rep(j,i+1,n) rt+=(s[j]=='0');
			if(rt>=6) return 1;
			else return 0;
		}
	return 0;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	check()?puts("yes"):puts("no");
	return 0;
}