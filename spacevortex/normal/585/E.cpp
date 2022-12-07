#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
#define upd(a,b) a=add(a,b)
#define rdc(a,b) a=sub(a,b)
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int add(int a,const int b){a+=b;if(a>=Mod)a-=Mod;return a;}
int sub(int a,const int b){a-=b;if(a<0)a+=Mod;return a;}
int mul(const int a,const int b){return (ll)a*b%Mod;}
int power(int x,int cs)
{
	int ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
const int N=5e5+50,V=1e7+50,pn=1e7+10;
int n,num=0,ans=0;
int pri[V>>2],mui[V],d[V],cnt[V],a[N],cf[N];
void init()
{
	int i,j;
	mui[1]=1;
	for(i=2;i<=pn;i++)
	{
		if(!d[i]) pri[++num]=i,d[i]=num,mui[i]=Mod-1;
		for(j=1;j<=d[i]&&i*pri[j]<=pn;j++)
		{
			d[i*pri[j]]=j;
			if(j==d[i]) mui[i*pri[j]]=0;
			else mui[i*pri[j]]=Mod-mui[i];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int i,j,val;
	init();
	cin>>n;
	for(i=1;i<=n;i++) 
	{
		cin>>a[i];cnt[a[i]]++;
	}
	for(i=1;i<=num;i++)
	{
		for(j=pn/pri[i];j>=1;j--)
		{
			cnt[j]+=cnt[pri[i]*j];
		}
	}
	cf[0]=1;
	for(i=1;i<=n;i++) cf[i]=mul(cf[i-1],2);
	val=0;
	for(i=1;i<=pn;i++)
	{
		if(cnt[i]) 
		{
			upd(val,mul(mui[i],mul(cf[cnt[i]-1],cnt[i])));
			rdc(ans,mul(mui[i],sub(cf[cnt[i]],1)));
		}
	}
	ans=add(mul(val,2),mul(ans,n));
	cout<<ans;
	return 0;
}