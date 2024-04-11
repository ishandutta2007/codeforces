#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
int n,k,ans;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int dv(int x,int y)
{
	return x/y+(bool)(x%y);
}

int query(int x)
{
	return x+dv(n,x);
}

int main()
{
//	freopen("a.out","w",stdout);
	n=getint();
	ans=n+n+10;
	rep(i,1,n)
		if(ans>query(i))
			ans=query(i),k=i;
	int p=n,cnt=dv(n,k);
	rep(i,1,cnt)
	{
		rep(j,p-k+1,p)
		{
			if(j<=0) continue;
			printf("%d ",j);
		}
		p=p-k;
	}
	puts("");
	return 0;
}