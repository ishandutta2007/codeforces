#include<algorithm>
#include<cctype>
#include<cstdio>
#include<cstring>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=300005;
int n,x,t[N<<2];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void modify(int l,int r,int rt)
{
	if(l==r)
	{
		t[rt]=1;
		return;
	}
	if(x<=mid) modify(l,mid,lch);
	else modify(mid+1,r,rch);
	if(t[rch]==r-mid) t[rt]=t[rch]+t[lch];
	else t[rt]=t[rch];
}

int main()
{
	n=getint();
	printf("1");
	rep(i,1,n)
	{
		x=getint(),modify(1,n,1);
		printf(" %d",i-t[1]+1);
	}
	puts("");
	return 0;
}