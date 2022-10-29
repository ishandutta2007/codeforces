#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
typedef long long LL;
const int N=2000005;
int n,R;
LL a[N],b[N],c[N],add[N],k;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL getLL()
{
	char ch;
	while(!isdigit(ch=getchar()));
	LL x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool check(LL x)
{
	memset(add,0,sizeof(add));
	LL tot=k;
	rep(i,1,n) b[i]=max(0ll,x-c[i]);
	rep(i,1,n)
	{
		add[i]+=add[i-1];
		LL nw=max(0ll,b[i]-add[i]);
		tot-=nw,add[i]+=nw,add[i+R+R+1]-=nw;
		if(tot<0) return 0;
	}
	return 1;
}

int main()
{
	n=getint(),R=getint(),k=getLL();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n)
	{
		int l=max(1,i-R),r=min(n,i+R);
		c[l]+=a[i],c[r+1]-=a[i];	
	}
	LL l=0,r=2e18;
	rep(i,1,n) c[i]+=c[i-1];
	while(l<=r)
		if(check(mid)) l=mid+1;
		else r=mid-1;
	return printf("%lld\n",l-1),0;
}