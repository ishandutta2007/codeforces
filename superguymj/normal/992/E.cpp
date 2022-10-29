#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<set>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=200005,M=35;
typedef long long LL;
typedef set <int> :: iterator it;
int n,m,a[N],x,y,id[M][2],ans;
LL c[M][2],t[N];
set <int> st[M];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void ins(int x,int y)
{
	for(int i=x; i<=n; i+=i&-i) t[i]+=y;
}

LL query(int x)
{
	LL rt=0;
	for(int i=x; i; i-=i&-i) rt+=t[i];
	return rt;
}

int get(int x)
{
	int rt=0;
	while(x) ++rt,x>>=1;
	return rt;
}

void build(int x)
{	
	it p=st[x].begin();
	id[x][0]=id[x][1]=c[x][0]=c[x][1]=0;
	for(int tp=0; tp<2 && p!=st[x].end(); ++tp,++p)
		id[x][tp]=*p,c[x][tp]=query(*p-1);
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,n) a[i]=t[i]=getint();
	rep(i,1,n) if(i+(i&-i)<=n) t[i+(i&-i)]+=t[i];
	rep(i,1,n) st[get(a[i])].insert(i);
	rep(i,0,30) build(i);
	while(m--)
	{
		x=getint(),y=getint();
		ins(x,y-a[x]);
		int p1=get(a[x]),p2=get(y);
		st[p1].erase(x),st[p2].insert(x);
		build(p1),build(p2);
		rep(i,0,30) if(i!=p1 && i!=p2)
			rep(j,0,1) if(id[i][j]>x)
				c[i][j]+=y-a[x];
		a[x]=y,ans=-1;
		rep(i,0,30)
		{		
			rep(j,0,1)
				if(id[i][j] && a[id[i][j]]==c[i][j])
				{
					ans=id[i][j];
					break;
				}
			if(ans!=-1) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}