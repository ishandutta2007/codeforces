#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
const int mod=998244353;
int n,t,ans,cnt,y[101],b[4];
array<int,2> a[51];
std::vector<int> v;
int solve(int t)
{
	for(int i=1;i<=n;i++)
	{
		y[i*2-1]=a[i][1]-t;
		y[i<<1]=a[i][1]+t+1;
	}
	sort(y+1,y+1+2*n);
	int res=0;
	for(int i=1;i<2*n;i++)
	{
		int lst=-INF;
		for(int l=1;l<=n;l++)
		{
			if(a[l][1]-t>y[i]||a[l][1]+t<y[i]||a[l][0]+t<=lst)
				continue;
			(res+=(y[i+1]-y[i])*(a[l][0]+t-max(lst,a[l][0]-t-1))%mod)%=mod;
			lst=a[l][0]+t;
		}
	}
	return res;
}
int qp(int x,int y)
{
	x%=mod;
	int res=1;
	while(y)
	{
		if(y&1)
			(res*=x)%=mod;
		(x*=x)%=mod;
		y>>=1;
	}
	return res;
}
signed main()
{
	n=read();
	t=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[i]={x,y};
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
			v.push_back((max(abs(a[i][0]-a[l][0]),abs(a[i][1]-a[l][1]))+1)/2);
	v.push_back(t);
	sort(ALL(v));
	int pre=0;
	// for(int i=0;i<t;i++)
		// (ans+=solve(i))%=mod;
	// cout<<(solve(t)*t%mod+mod-ans)%mod<<'\n';
	ans=0;
	for(int i:v)
	{
		if(i>t)
			break;
		int tot=i-pre;
		if(!tot)
			continue;
		// cout<<i<<" "<<tot<<endl;
		b[0]=solve(pre);
		for(int i=1;i<min(4ll,tot);i++)
			b[i]=(b[i-1]+solve(pre+i))%mod;
		if(tot<4)
			(ans+=b[tot-1])%=mod;
		else
		{
			int res=0;
			for(int l=0;l<4;l++)
			{
				int k=b[l];
				for(int j=0;j<4;j++)
					if(l!=j)
						(k*=qp(mod+l-j,mod-2)*(tot+mod-1-j)%mod)%=mod;
				(res+=k)%=mod;
			}
			// cout<<res<<" ";
			// res=0;
			// for(int l=pre;l<i;l++)
			// {
				// (res+=solve(l))%=mod;
				// cout<<res<<" ";
			// }
			// cout<<endl;
			// cout<<res<<'\n';
			(ans+=res)%=mod;
		}
		pre=i;
	}
	// cout<<ans<<endl;
	// cout<<solve(t)<<endl;
	cout<<(solve(t)*t%mod+mod-ans)%mod;
	return 0;
}