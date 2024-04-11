#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=400005,mod=1000000007;
int n,m,a[N],lst[N];
LL f[N],t[N],ans;
struct data{int a,b;} dat[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL add(LL x,LL y)
{
	if((x+=y)>=mod) x-=mod;
	return x;
}

void ins(int x,LL y)
{
	for(int i=x; i; i-=i&-i) t[i]=add(t[i],y);
}

LL query(int x)
{
	LL ret=0;
	for(int i=x; i<=2*n; i+=i&-i) ret=add(ret,t[i]);
	return ret;
}

void init()
{
	rep(i,1,2*n)
		if(lst[i])
			f[i]=add(query(lst[i]),1),ins(lst[i],f[i]);
}

bool cmp(int x,int y)
{
	return dat[x].b>dat[y].b;
}

void solve()
{
	int p=0,x=2*n;
	rep(i,1,m)
	{
		rep(j,dat[a[i]].b,x) if(lst[j]) ins(lst[j],mod-f[j]);
		x=dat[a[i]].b-1;
		if(dat[a[i]].a<p) continue;
		ans=add(ans,query(p+1)+1);
		p=dat[a[i]].a;
	}
}

int main()
{
	n=getint();
	rep(i,1,n) dat[i].a=getint(),dat[i].b=getint(),lst[dat[i].b]=dat[i].a;
	init();
	m=getint();
	rep(i,1,m) a[i]=getint();
	sort(a+1,a+1+m,cmp);
	solve();
	printf("%lld\n",ans);
	return 0;
}