#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,k,w;
ll hc,dc,hm,dm,a;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&hc,&dc);
		scanf("%lld%lld",&hm,&dm);
		scanf("%d%d%lld",&k,&w,&a);
		bool f=false;
		for(int i=0;i<=k;i++)
		{
			ll atk1=(hm+dc+w*i-1)/(dc+w*i);
			ll atk2=(hc+a*(k-i)+dm-1)/dm;
			if(atk1<=atk2) {f=true; break;}
		}
		if(f) puts("YES"); else puts("NO");
	}
	return 0;
}