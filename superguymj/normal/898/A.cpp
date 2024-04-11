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
int n,x;

int main()
{
	scanf("%d",&n);
	x=n%10,n/=10;
	if(x>5) ++n;
	if(n)
		printf("%d",n);
	puts("0");
	return 0;
}