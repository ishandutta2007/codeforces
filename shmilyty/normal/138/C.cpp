#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
map<int,long double> mp;
unordered_map<int,int> mp1,mp2;
int n,m,now,cnt2,tot;
long double cnt=1,ans;
array<int,4> a[100001];
array<int,2> b[10001]; 
void work(int x,int y,long double v)
{
	mp[x]*=v;
	mp2[x]-=2;
	while(mp[x]>=1e3)
	{
		mp[x]*=0.001;
		mp2[x]+=3;
	}
	mp[y]/=v;
	mp2[y]+=2;
	while(mp[y]<=10&&mp2[y]>0)
	{
		mp[y]*=10.0;
		mp2[y]--;
	}
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		int x1=read(),x2=read(),x3=read(),x4=read();
		a[i]={x1,x2,x3,x4};
		mp[x1]=1;
		mp[x1-x2]=1;
		mp[x1+1]=1; 
		mp[x1+x2+1]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][2]==100)
		{
			mp1[a[i][0]-a[i][1]]++;
			mp1[a[i][0]]--;
		}
		else
		{
			work(a[i][0]-a[i][1],a[i][0],100-a[i][2]);
//			mp[a[i][0]-a[i][1]]*=((100-a[i][2])/100.0);
//			mp[a[i][0]]*=(100.0/((long double)100.0-a[i][2]));
		}
		if(a[i][3]==100)
		{
			mp1[a[i][0]+1]++;
			mp1[a[i][0]+a[i][1]+1]--;
		}
		else
		{
			work(a[i][0]+1,a[i][0]+a[i][1]+1,100-a[i][3]);
//			mp[a[i][0]+1]*=((100-a[i][3])/100.0);
//			mp[a[i][0]+a[i][1]+1]*=(100.0/((long double)100.0-a[i][3]));	
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		b[i]={x,y};
	}
	sort(b+1,b+1+m);
	for(auto i:mp)
	{
		while(now<=m&&b[now+1][0]<i.first)
			if(!cnt2)
			{
				long double res=1.0*cnt*b[++now][1];
				if(tot>0)
					for(int l=1;l<=tot;l++)
						res*=10.0;
				else
					for(int l=1;l<=-tot&&res>=1e-7;l++)
						res*=0.1;
				ans+=res;
			}
			else
				now++;
		cnt*=i.second;
		tot+=mp2[i.first];
		while(cnt>=1e3)
		{
			cnt*=0.001;
			tot+=3;
		}
		while(cnt<=10&&tot>0)
		{
			cnt*=10.0;
			tot--;
		}
		cnt2+=mp1[i.first];
	}
	while(now<=m)
		if(!cnt2)
		{
			long double res=1.0*cnt*b[++now][1];
			if(tot>0)
				for(int i=1;i<=tot;i++)
					res*=10.0;
			else
				for(int i=1;i<=-tot&&res>1e-7;i++)
					res*=0.1;
			ans+=res;
		}
		else
			now++;
	printf("%.10Lf",ans);
	return 0;
}