#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=100005;
int n,mn;
LL l[N],s,G,W;

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

int main()
{
	n=getint(),mn=5;
	rep(i,1,n) l[i]=getLL(),s+=(l[i]*=2);
	rep(i,1,n)
	{
		char c=getchar();
		if(c=='G') G+=l[i];
		if(c=='W') W+=l[i],mn=3;
		LL t=l[i],e;
		e=min(t/2,W),s+=2*e,t-=2*e,W-=e;
		e=min(t/2,G),s+=4*e,t-=2*e,G-=e;
		s+=t*mn;
	}
	printf("%lld\n",s/2);
	return 0;
}