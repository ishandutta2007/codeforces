#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
typedef long long LL;
const int N=200005;
int n,x,s[N],s1[N],s2[N],a[N];
LL ans;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool jdg(int x)
{
	int rt=sqrt(x);
	return rt*rt==x;
}

void task1()
{
	x=(s1[0]-s2[0])/2;
	repd(i,*s1,*s1-x+1)
		if(s1[i]) ++ans;
		else ans+=2;
	printf("%I64d\n",ans);
}

int query(int x)
{
	int l=1,r=31623;
	while(l<=r)
		s[mid]<=x?l=mid+1:r=mid-1;
	return min(x-s[l-1],s[l]-x);
}

void task2()
{
	x=(s2[0]-s1[0])/2;
	rep(i,1,*s2) a[i]=query(s2[i]);
	sort(a+1,a+1+*s2);
	rep(i,1,x) ans+=a[i];
	printf("%I64d\n",ans);
}

int main()
{
	n=getint();
	rep(i,1,31623) s[i]=i*i;
	s[31624]=2000000000;
	rep(i,1,n)
	{
		a[i]=getint();
		if(jdg(a[i])) s1[++*s1]=a[i];
		else s2[++*s2]=a[i];
	}
	sort(s1+1,s1+1+*s1);
	sort(s2+1,s2+1+*s2);
	if(*s1==*s2) return puts("0"),0;
	if(*s1>*s2) task1();
	else task2();
	return 0;
}