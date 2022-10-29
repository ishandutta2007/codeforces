#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=1000005,K=25;
int n,m,k,ql,qr;
char s[K],t[K];
int a[N],b[N],s1,t1,bt,p[K];
int fs[N<<1],ft[N<<1],bin[N<<1],ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void trf(int x,int y)
{
	int X,Y;
	rep(i,1,k)
	{
		if(p[i]==x) X=i;
		if(p[i]==y) Y=i;
	}
	swap(p[X],p[Y]);
	int bX=(bool)(bt&(1<<X-1));
	int bY=(bool)(bt&(1<<Y-1));
	if(bX^bY) bt^=(1<<X-1)^(1<<Y-1);
}

int main()
{
	n=getint(),m=getint(),k=getint();
	scanf("%s",s+1),scanf("%s",t+1);
	rep(i,1,n) a[i]=getint(),b[i]=getint();
	rep(i,1,k)
	{
		if(s[i]=='1') ++s1;
		if(t[i]=='1') ++t1;
	}
	
	bt=0;
	rep(i,1,k) if(s[i]=='1') bt|=(1<<i-1);
	rep(i,1,k) p[i]=i;
	rep(i,0,(1<<k)-1) fs[i]=n+1;
	repd(i,n,1)
	{
		trf(a[i],b[i]);
		fs[bt]=i;
	}
	repd(i,(1<<k)-1,0)
		rep(j,0,k-1) if(i&(1<<j))
			fs[i^(1<<j)]=min(fs[i^(1<<j)],fs[i]);
	
	bt=0;
	rep(i,1,k) if(t[i]=='1') bt|=(1<<i-1);
	rep(i,1,k) p[i]=i;
	rep(i,0,(1<<k)-1) ft[i]=0;
	repd(i,n,1)
	{
		ft[bt]=max(ft[bt],i+1);
		trf(a[i],b[i]);
	}
	repd(i,(1<<k)-1,0)
		rep(j,0,k-1) if(i&(1<<j))
			ft[i^(1<<j)]=max(ft[i^(1<<j)],ft[i]);

	ans=-1;
	rep(i,1,(1<<k)-1)
	{
		bin[i]=bin[i^(i&-i)]+1;
		if(ft[i]-fs[i]>=m && ans<bin[i]) ans=bin[i],ql=fs[i],qr=ft[i]-1;
	}
	printf("%d\n",k-(s1-ans)-(t1-ans));
	printf("%d %d\n",ql,qr);
	return 0;
}