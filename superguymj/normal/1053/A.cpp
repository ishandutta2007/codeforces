#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int x,y,n,m,k;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

int main()
{
	x=n=getint(),y=m=getint(),k=getint();
	int a=gcd(n,k);
	n/=a,k/=a;
	a=gcd(m,k);
	m/=a,k/=a;
	if(k!=1 && k!=2) return puts("NO"),0;
	if(k==2)
	{
		puts("YES");
		printf("0 0\n%d %d\n%d %d\n",0,m,n,0);
	}
	else
	{
		if(n*2<=x) n*=2;
		else if(m*2<=y) m*=2;
		else return puts("NO"),0;
		puts("YES");
		printf("0 0\n%d %d\n%d %d\n",0,m,n,0);
	}
	return 0;
}