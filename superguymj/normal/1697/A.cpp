#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid ((l+r)>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
typedef long long LL;
int n,m;

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
	int T=getint();
	while(T--)
	{
		n=getint(),m=getint();
		int tot=0;
		rep(i,1,n) tot+=getint();
		tot-=m;
		if(tot>=0) printf("%d\n",tot);
		else puts("0");
	}
	return 0;
}