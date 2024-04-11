#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
using namespace std;
const int N=1e5+5;
int T;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
map<pair<int,int>,int> M;
map<pair<int,int>,int>::iterator it;
pair<int,int> rev(pair<int,int> a){return mk(-a.first,-a.second);}
int n; ll Ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		Ans=0,M.clear(),scanf("%d",&n);
		for(int x,y,u,v,i=1;i<=n;i++)
		{
			scanf("%d%d%d%d",&x,&y,&u,&v),x=u-x,y=v-y;
			int d=abs(gcd(x,y)); x/=d,y/=d; ++M[mk(x,y)];
		}
		for(it=M.begin();it!=M.end();++it)
			Ans=Ans+1ll*M[rev(it->first)]*(it->second);
		printf("%lld\n",Ans/2);
	}
	return 0;
}