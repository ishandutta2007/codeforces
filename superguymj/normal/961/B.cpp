#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
int n,k,s[100005],a[100005],mx,ans;

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
	n=getint(),k=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n)
	{
		if(getint())
		{
			ans+=a[i];
			s[i]=s[i-1];
		}
		else s[i]=s[i-1]+a[i];
	}
	rep(i,1,n-k+1) mx=max(mx,s[i+k-1]-s[i-1]);
	printf("%d\n",mx+ans); 
	return 0;
}