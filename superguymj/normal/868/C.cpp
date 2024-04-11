#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int n,k,x,c[N],bin[4],tot,a[100];
bool vis[100],Vis;

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
	n=getint(),k=getint();
	rep(i,1,n)
	{
		x=0;
		rep(j,1,k) x=x<<1|(getint());
		c[i]=x;
	}
	rep(i,1,n) if(!vis[c[i]]) vis[c[i]]=1,a[++tot]=c[i];
	rep(i,1,(1<<tot)-1)
	{
		x=bin[0]=bin[1]=bin[2]=bin[3]=Vis=0;
		rep(j,0,tot-1)
			if(i&(1<<j))
			{
				++x;
				bin[0]+=(bool)(a[j+1]&1);
				bin[1]+=(bool)(a[j+1]&2);
				bin[2]+=(bool)(a[j+1]&4);
				bin[3]+=(bool)(a[j+1]&8);
			}
		rep(j,0,3)
			if(bin[j]*2>x)
			{
				Vis=1;
				break;
			}
		if(!Vis)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}