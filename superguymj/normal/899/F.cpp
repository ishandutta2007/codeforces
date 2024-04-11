#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=200005;
char s[N],ch[0];
int n,m,ql,qr,x,t[63][N<<2];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int trf(char c)
{
	if('0'<=c && c<='9') return c-'0'+1;
	if('a'<=c && c<='z') return 10+c-'a'+1;
	return 36+c-'A'+1;
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		t[0][rt]=t[trf(s[l])][rt]=1;
		return;
	}
	build(l,mid,lch);
	build(mid+1,r,rch);
	rep(i,0,62) t[i][rt]=t[i][lch]+t[i][rch];
}

int find(int l,int r,int rt,int x)
{
	if(l==r) return l;
	int tot=t[0][lch];
	if(tot>=x) return find(l,mid,lch,x);
	else return find(mid+1,r,rch,x-tot);
}

void dec(int l,int r,int rt,int x)
{
	if(l==r)
	{
		t[0][rt]=0;
		return;
	}
	if(x<=mid) dec(l,mid,lch,x);
	else dec(mid+1,r,rch,x);
	t[0][rt]=t[0][lch]+t[0][rch];
}

void modify(int l,int r,int rt)
{
	if(!t[x][rt]) return;
	if(l==r)
	{
		dec(1,n,1,l),t[x][rt]=0;
		return;
	}
	if(ql<=mid) modify(l,mid,lch);
	if(mid<qr) modify(mid+1,r,rch);
	t[x][rt]=t[x][lch]+t[x][rch];
}

void PRT(int l,int r,int rt)
{
	if(l==r)
	{
		if(t[0][rt]) printf("%c",s[l]);
		return;
	}
	PRT(l,mid,lch),PRT(mid+1,r,rch);
}

int main()
{
	n=getint(),m=getint();
	scanf("%s",s+1),build(1,n,1);
	while(m--)
	{
		ql=getint(),qr=getint(),scanf("%s",ch);
		ql=find(1,n,1,ql),qr=find(1,n,1,qr),x=trf(ch[0]);
		if(ql<=qr) modify(1,n,1);
	}
	PRT(1,n,1),puts("");
	return 0;
}