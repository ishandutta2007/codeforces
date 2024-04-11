#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
bool vis;
const int N=1005;
int n,a[N],b[N],k1,k2;
typedef long long LL;
struct data{int a,b; LL c;} dat[N];

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
	n=getint(),k1=getint(),k2=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) b[i]=getint();
	rep(i,1,n) dat[i]=(data){a[i],b[i],(LL)(a[i]-b[i])*(a[i]-b[i])};
	while(k1)
	{
		int id=0;
		rep(i,1,n) if(!id || dat[i].c>dat[id].c) id=i;
		if(dat[id].c==0) {vis=1; break;}
		if(dat[id].a<dat[id].b) ++dat[id].a;
		else --dat[id].a;
		dat[id].c=(LL)(dat[id].a-dat[id].b)*(dat[id].a-dat[id].b);
		--k1;
	}
	if(!vis)
	{
		while(k2)
		{
			int id=0;
			rep(i,1,n) if(!id || dat[i].c>dat[id].c) id=i;
			if(dat[id].c==0) {vis=1; break;}
			if(dat[id].a<dat[id].b) --dat[id].b;
			else ++dat[id].b;
			dat[id].c=(LL)(dat[id].a-dat[id].b)*(dat[id].a-dat[id].b);
			--k2;
		}
	}
	if(vis)
	{
		if((k1+k2)&1) puts("1");
		else puts("0");
	}
	else
	{
		LL ans=0;
		rep(i,1,n) ans+=dat[i].c;
		printf("%I64d\n",ans);
	}
	return 0;
}