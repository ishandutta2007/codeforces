#include<ctime>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define N 3000030

using namespace std;

int l,r,p,now,next,nowx,ans,last,v;
int prime[110],q[N],f[N],flag[N],Q[N],Ans[N];

void dfs(int x,int nowsum)
{
	if(x>prime[0])
	{
		q[++q[0]]=nowsum;
		return;
	}
	dfs(x+1,nowsum);
	int nowpow=1;
	while(1ll*nowsum*nowpow*prime[x]<=r)
	{
		dfs(x+1,nowsum*nowpow*prime[x]);
		if(1ll*nowpow*prime[x]>r)return;
		nowpow=nowpow*prime[x];
	}
}

int main()
{
	scanf("%d%d%d",&l,&r,&p);
	for(int i=2;i<=p;i++)
	{
		for(int j=2;j*j<=i;j++)
			if(i%j==0)goto la;
		prime[++prime[0]]=i;
		la:;
	}
	dfs(1,1);
	sort(q+1,q+1+q[0]);
	memset(f,0x3f,sizeof(f));
	f[1]=0;
	for(int i=2;i<=p;i++)
	{
		nowx=1;
		for(int j=1;j<=q[0]&&nowx<=q[0];j++)
		{
			while(nowx<=q[0]&&1ll*q[j]*i>q[nowx])nowx++;
			if(f[j]+i>=p)continue;
			f[nowx]=min(f[nowx],f[j]+1);
			if(q[nowx]>=l)Ans[nowx]=1;
		}
	}
	for(int i=1;i<=q[0];i++)
		ans+=Ans[i];
	printf("%d\n",ans);
}