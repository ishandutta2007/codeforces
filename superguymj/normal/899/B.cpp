#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
int n,a[30];
const int p[]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,0,35)
	{
		bool jdg=0;
		rep(j,1,n)
		{
			int x=(i+j)%36;
			if(a[j]!=p[x]) {jdg=1; break;}
		}
		if(!jdg)
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}