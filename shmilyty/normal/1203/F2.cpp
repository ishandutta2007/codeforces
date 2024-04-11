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
int n,r,ans,c1,c2,res,f[101][60001];
array<int,2> a[101],b[101];
bool cmp(array<int,2> x,array<int,2> y)
{
//	if(x[0]+x[1]==y[0]+y[1])
//		return x[0]<=y[1];
	return x[0]+x[1]>y[0]+y[1];
//	return max(x[0],y[0]-x[1])<=max(y[0],x[0]-y[1]);
} 
signed main()
{
	n=read();
	r=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		if(y>=0)
			a[++c1]={x,y};
		else
			b[++c2]={x,y};
	}
	sort(a+1,a+1+c1);
	sort(b+1,b+1+c2,cmp);
	for(int i=1;i<=c1;i++)
		if(r>=a[i][0])
		{
			r+=a[i][1];
			ans++;
		}
		else
			break;
//	cout<<ans<<endl;
	for(int i=1;i<=c2;i++)
		if(r>=b[i][0]&&r>=-b[i][1])
		{
			f[i][r+b[i][1]]=1;
			res=max(res,1ll);
			for(int j=i-1;j>=1;j--)
				for(int l=max(-b[i][1],b[i][0]);l<=6e4;l++)
					if(f[j][l])
					{
						f[i][l+b[i][1]]=max(f[j][l]+1,f[i][l+b[i][1]]);
						res=max(res,f[i][l+b[i][1]]);
					}
		}
//	cout<<c2<<" "<<res<<endl;
	cout<<ans+res;
	return 0;
}