#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
typedef long long LL;
const int N=3005;
bool vis[N];
int n,m,nw;
const LL INF=1000000000000000;
LL ans;
struct data{int id; LL c;} dat[N];
vector <data> vt[N];

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

bool cmp(data a,data b)
{
	return a.c<b.c;
}

LL check(int x)
{
	LL rt=0;
	int cnt=x-(int)(vt[1].size());
	rep(i,1,n) vis[i]=0;
	rep(i,2,m)
	{
		int siz=vt[i].size();
		rep(j,0,siz-x) --cnt,rt+=vt[i][j].c,vis[vt[i][j].id]=1;
	}
	rep(i,1,n)
	{
		if(cnt<=0) break;
		if(vis[i] || dat[i].id==1) continue;
		--cnt,rt+=dat[i].c;
	}
	if(cnt>0) return INF;
	return rt;
}

int main()
{
	n=getint(),m=getint(),ans=INF;
	rep(i,1,n) dat[i].id=getint(),dat[i].c=getint();
	sort(dat+1,dat+1+n,cmp);
	rep(i,1,n) vt[dat[i].id].pb((data){i,dat[i].c});
	nw=max(1,(int)vt[1].size());
	rep(i,nw,n)
		ans=min(ans,check(i));
	printf("%lld\n",ans);
	return 0;
}