#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int X,d;
long long bin[50],ans[100000];

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
	scanf("%d%d",&X,&d);
	rep(i,1,31) bin[i]=(1ll<<i)-1;
	long long nw=1;
	int p=31;
	while(X)
	{
		while(X-bin[p]<0) --p;
		rep(i,1,p) ans[++*ans]=nw;
		nw+=d,X-=bin[p];
	}
	printf("%I64d\n",*ans);
	rep(i,1,*ans-1) printf("%I64d ",ans[i]);
	printf("%I64d\n",ans[*ans]);
	return 0;
}