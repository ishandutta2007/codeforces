#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}
int n,a,b;

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	rep(i,0,10000000)
	{
		if(a*i>n) break;
		if((n-a*i)%b==0)
		{
			printf("YES\n%d %d\n",i,(n-a*i)/b);
			return 0;
		}
	}
	puts("NO");
}