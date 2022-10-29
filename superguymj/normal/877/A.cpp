#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
char s[1000];
int n,tot;

void solve(char *c)
{
	int len=strlen(c);
	rep(i,1,n-len+1)
	{
		bool vis=0;
		rep(j,0,len-1)
			if(c[j]!=s[i+j])
			{
				vis=1;
				break;
			}
		tot+=(!vis);
	}
}

int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	char n1[]="Danil";
	char n2[]="Olya";
	char n3[]="Slava";
	char n4[]="Ann";
	char n5[]="Nikita";
	solve(n1);
	solve(n2);
	solve(n3);
	solve(n4);
	solve(n5);
	if(tot==1) puts("YES");
	else puts("NO");
	return 0;
}