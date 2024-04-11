#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=100005;
int n,m,a[N],b[N],p;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int get(int i,int j)
{
	return abs(a[i]-b[j])+abs(b[j]-p);
}

bool check(int x)
{
	int l=1;
	rep(i,1,m)
	{
		if(get(l,i)<=x) ++l;
		if(l>n) return 1;
	}
	return 0;
}

int main()
{
	n=getint(),m=getint(),p=getint();
	rep(i,1,n) a[i]=getint();
	sort(a+1,a+1+n);
	rep(i,1,m) b[i]=getint();
	sort(b+1,b+1+m);
	int l=0,r=2000000000;
	while(l<=r)
	{
		int mid=((LL)l+r)/2;
		if(check(mid))
			r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",r+1);
	return 0;
}