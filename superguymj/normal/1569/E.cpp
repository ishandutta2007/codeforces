#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define pb push_back
 
using namespace std;
const int N=100,mod=998244353;
typedef long long LL;
bool jdg;
LL A,h,bin[N];
int n,k,id[N][N],p[N],a[N];
map <int,vector <int>> mp[3];
 
LL calc()
{
	LL ans=0;
	rep(i,1,n) if(p[i]) ans=(ans+i*bin[p[i]])%mod;
	return ans;
}
 
void solve1(int n,int tp=0)
{
	if(n==1)
	{
		rep(i,1,2)
		{
			p[id[tp][1]]=i;
			LL x=calc();
			vector <int> vt;
			vt.clear();
			rep(j,1,::n>>1) vt.pb(p[j]);
			mp[i][x]=vt;
		}
		return;
	}
	rep(s,0,(1<<(n>>1))-1)
	{
		rep(i,0,(n>>1)-1)
		{
			if(s&(1<<i)) id[tp+1][i+1]=id[tp][i*2+1],p[id[tp][i*2+2]]=a[tp];
			else id[tp+1][i+1]=id[tp][i*2+2],p[id[tp][i*2+1]]=a[tp];
		}
		solve1(n>>1,tp+1);
	}
}
 
void solve2(int n,int tp=0)
{
	if(n==1)
	{
		rep(i,1,2)
		{
			int t=i==1?2:1;
			p[id[tp][1]]=i;
			LL x=(h-calc()+mod)%mod;
			if(mp[t].count(x))
			{
				jdg=1;
				rep(j,1,::n>>1) printf("%d ",mp[t][x][j-1]);
				rep(j,(::n>>1)+1,::n) printf("%d ",p[j]);
				puts("");
				return;
			}
		}
		return;
	}
	rep(s,0,(1<<(n>>1))-1)
	{
		rep(i,0,(n>>1)-1)
		{
			if(s&(1<<i)) id[tp+1][i+1]=id[tp][i*2+1],p[id[tp][i*2+2]]=a[tp];
			else id[tp+1][i+1]=id[tp][i*2+2],p[id[tp][i*2+1]]=a[tp];
		}
		solve2(n>>1,tp+1);
		if(jdg) return;
	}
}
 
int main()
{
	scanf("%d%lld%lld",&k,&A,&h),n=1<<k;
	rep(i,1,k) a[i-1]=(1<<k-i)|1;
	bin[0]=1;
	rep(i,1,n) bin[i]=bin[i-1]*A%mod;
	rep(i,1,n>>1) id[0][i]=i;
	solve1(n>>1);
	rep(i,1,n>>1) p[i]=0;
	rep(i,1,n>>1) id[0][i]=i+(n>>1);
	solve2(n>>1);
	if(!jdg) puts("-1");
	return 0;
}