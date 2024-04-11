#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=2005;
bool jdg;
int n,rt,ans,p,a[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void task1()
{
	a[n+1]=1,ans=0;
	rep(i,1,n+1)
		if(a[i]==1) ans+=i-1-p,p=i;
	printf("%d\n",ans);
}

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

bool check()
{
	rt=0;
	rep(i,1,n) rt=gcd(rt,a[i]);
	if(rt!=1) return 1;
	else return 0;
}

void task2()
{
	ans=1e9;
	rep(i,1,n-1)
	{
		rt=a[i];
		rep(j,i+1,n)
		{
			rt=gcd(rt,a[j]);
			if(rt==1) ans=min(ans,j-i+n-1);
		}
	}
	printf("%d\n",ans);
}

int main()
{
	n=getint();
	rep(i,1,n) if((a[i]=getint())==1) jdg=1;
	if(jdg) task1();
	else if(check()) puts("-1");
	else task2();
	return 0;
}