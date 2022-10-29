#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=1<<20;
char s[N];
int k,q,t[N<<1],x,n;
char c;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void pushup(int rt)
{
	int p=n-rt+1;
	if(s[p]=='0') t[rt]=t[rch];
	if(s[p]=='1') t[rt]=t[lch];
	if(s[p]=='?') t[rt]=t[lch]+t[rch];
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		t[rt]=1;
		return;
	}
	build(l,mid,lch);
	build(mid+1,r,rch);
	pushup(rt);
}

int main()
{
	scanf("%d%s",&k,s+1),n=strlen(s+1);
	build(0,n,1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %c",&x,&c),s[x]=c;
		for(x=n-x+1; x; x>>=1) pushup(x);
		printf("%d\n",t[1]);
	}
	return 0;
}