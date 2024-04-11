#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=20,M=300000;
int n,m,a,b,c1[N],c2[N],tot1,tot2,d1[M],d2[M],p,ans;

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
	n=getint(),m=getint(),a=n>>1,b=n-a;
	rep(i,1,a) c1[i]=getint()%m;
	rep(i,1,b) c2[i]=getint()%m;
	rep(i,0,(1<<a)-1)
	{
		++tot1;
		rep(j,1,a)
			if(i&(1<<j-1))
				d1[tot1]=(d1[tot1]+c1[j])%m;
		ans=max(d1[tot1],ans);
	}
	rep(i,0,(1<<b)-1)
	{
		++tot2;
		rep(j,1,b)
			if(i&(1<<j-1))
				d2[tot2]=(d2[tot2]+c2[j])%m;
		ans=max(d2[tot2],ans);
	}
	sort(d1+1,d1+1+tot1);
	sort(d2+1,d2+1+tot2);
	p=tot2;
	rep(i,1,tot1)
	{
		while(d2[p]+d1[i]>=m) --p;
		ans=max(ans,d2[p]+d1[i]);
	}
	printf("%d\n",ans);
	return 0;
}