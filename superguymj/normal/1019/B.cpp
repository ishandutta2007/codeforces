#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
typedef long long LL;
int n;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

LL getLL()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	LL x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

bool check(int a,int b)
{
	if(a<0 && b<0) return 1;
	if(a>0 && b>0) return 1;
	return 0;
}

int main()
{
	scanf("%d",&n);
	printf("? %d\n",1),fflush(stdout);
	int a,b;
	scanf("%d",&a);
	printf("? %d\n",n/2+1),fflush(stdout);
	scanf("%d",&b);
	int x=a-b,y=b-a;
	if(x==0) return puts("! 1"),fflush(stdout),0;
	if(abs(x)&1) return puts("! -1"),fflush(stdout),0;
	int l=2,r=n/2;
	while(l<=r)
	{
		printf("? %d\n",mid),fflush(stdout);
		scanf("%d",&a);
		printf("? %d\n",mid+n/2),fflush(stdout);
		scanf("%d",&b);
		if(a==b) return printf("! %d\n",mid),fflush(stdout),0;
		if(check(a-b,x)) l=mid+1; else r=mid-1;
	}
	return 0;
}