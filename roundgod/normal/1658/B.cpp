#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int fact[MAXN];
int main()
{
	fact[0]=1;
	for(int i=1;i<=1000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n&1) puts("0");
		else
		{
			int ans=1LL*fact[n/2]*fact[n/2]%MOD;
			printf("%d\n",ans);
		}
	}
	return 0;
}