#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll k,x,y;
ll a[4][4],b[4][4];
ll cnt1[100],cnt2[100];
ll used[4][4];
ll judge(ll p, ll q)
{
	if(p==3&&q==2) return 1;
	if(p==2&&q==1) return 1;
	if(p==1&&q==3) return 1;
	return 0;
}
int main()
{
	scanf("%I64d%I64d%I64d",&k,&x,&y);
	for(ll i=1;i<=3;i++)
		for(ll j=1;j<=3;j++)
			scanf("%I64d",&a[i][j]);
	for(ll i=1;i<=3;i++)
		for(ll j=1;j<=3;j++)
			scanf("%I64d",&b[i][j]);
	memset(cnt1,0,sizeof(cnt1));
	memset(cnt2,0,sizeof(cnt2));
	memset(used,-1,sizeof(used));
	ll nx=x,ny=y,t=1;
	cnt1[t]=judge(nx,ny);
	cnt2[t]=judge(ny,nx);
	used[nx][ny]=1;
	t++;
	ll tt=a[nx][ny];
	ny=b[nx][ny];
	nx=tt;
	while(used[nx][ny]==-1)
	{
		used[nx][ny]=t;
		cnt1[t]=judge(nx,ny);
		cnt2[t]=judge(ny,nx);
		t++;
		tt=a[nx][ny];
		ny=b[nx][ny];
		nx=tt;
	}
	for(ll i=1;i<t;i++)
	{
		cnt1[i]+=cnt1[i-1];
		cnt2[i]+=cnt2[i-1];
	}
	ll period=t-used[nx][ny];
	ll sum1=cnt1[t-1]-cnt1[used[nx][ny]-1],sum2=cnt2[t-1]-cnt2[used[nx][ny]-1];
	ll ans1=cnt1[used[nx][ny]-1],ans2=cnt2[used[nx][ny]-1];
	if(k<=used[nx][ny]-1)
	{
		printf("%I64d %I64d\n",cnt1[k],cnt2[k]);
		return 0;
	}
	k-=used[nx][ny]-1;
	printf("%I64d %I64d\n",ans1+(k/period)*sum1+(k%period==0?0:cnt1[used[nx][ny]+(k%period)-1]-cnt1[used[nx][ny]-1]),ans2+(k/period)*sum2+(k%period==0?0:cnt2[used[nx][ny]+(k%period)-1]-cnt2[used[nx][ny]-1]));
	return 0;
}