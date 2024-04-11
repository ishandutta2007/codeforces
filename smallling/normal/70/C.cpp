#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

struct lhy{
	int x,y;
};

map<pair<int,int>,int>a,b;

int ans1,ans2,now,w,nowans,n,m,rev[100010],Gcd[100010];
long long ans,sum;

int rever(int now)
{
	nowans=0;
	while(now)
	{
		nowans=nowans*10+now%10;
		now/=10;
	}
	return nowans;
}

int gcd(int a,int b)
{
	return a%b==0?b:gcd(b,a%b);
}

int main()
{
	scanf("%d%d%d",&n,&m,&w);
	for(int i=1;i<=100000;i++)
	{
		rev[i]=rever(i),Gcd[i]=gcd(i,rev[i]);
		if(i<=n)a[make_pair(rev[i]/Gcd[i],i/Gcd[i])]++;
	}
	now=n;
	ans=1e17;
	for(int i=1;i<=m;i++)
	{
		sum+=a[make_pair(i/Gcd[i],rev[i]/Gcd[i])];
		b[make_pair(i/Gcd[i],rev[i]/Gcd[i])]++;
		while(sum-b[make_pair(rev[now]/Gcd[now],now/Gcd[now])]>=w)
		{
			sum-=b[make_pair(rev[now]/Gcd[now],now/Gcd[now])];
			a[make_pair(rev[now]/Gcd[now],now/Gcd[now])]--;
			now--;
		}
		if(sum>=w)
		{
			if(1ll*i*now<ans)
			{
				ans=1ll*i*now;
				ans1=i;
				ans2=now;
			}
		}
	}
	if(ans==1e17)return puts("-1"),0;
	printf("%d %d",ans2,ans1);
}