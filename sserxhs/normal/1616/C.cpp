#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=72;
int a[N];
struct Q
{
	int x,y;
	Q(int a,int b)
	{
		if (b<0) a=-a,b=-b;
		int z=abs(gcd(a,b));
		a/=z;b/=z;
		x=a;y=b;
	}
	bool operator<(const Q &o) const {return x*o.y<y*o.x;}
};
map<Q,int> f[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,i,j,ans=1;
		cin>>n;for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i++) f[i].clear();
		for (i=1;i<=n;i++)
		{
			for (j=1;j<i;j++)
			{
				auto r=Q(a[i]-a[j],i-j);
				ans=max(ans,f[i][r]=max(f[i][r],max(1,f[j][r])+1));
			}
		}
		cout<<n-ans<<'\n';
	}
}