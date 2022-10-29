#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,a[1005];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) if(a[i]%a[1]) {puts("-1"); return 0;}
	printf("%d\n",2*n-1);
	rep(i,2,n) printf("%d %d ",a[1],a[i]);
	printf("%d\n",a[1]);
	return 0;
}