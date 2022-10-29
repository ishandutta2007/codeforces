#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=100005;
const LL INF=10000000000000000;
int n,k;
LL a[N],ans;
map <LL,int> mp;

int main()
{
	cin>>n>>k;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n) a[i]+=a[i-1];
	mp[0]=1;
	rep(i,1,n)
	{
		if(k==1) ans+=mp[a[i]-1];
		else if(k==-1) ans+=mp[a[i]+1]+mp[a[i]-1];
		else
		{
			LL x=1;
			rep(j,1,100)
			{
				ans+=mp[a[i]-x];
				x*=k;
				if(abs(x)>INF) break;
			}
		}
		++mp[a[i]];
	}
	printf("%lld\n",ans);
	return 0;
}