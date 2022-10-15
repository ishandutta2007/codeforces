#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a,b;
int dist[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		if(a>=b) printf("%d\n",a-b);
		else
		{
			int ans=b-a;
			for(int i=b;i<=2*b;i++) if((a|i)==i) ans=min(ans,i-b+1);
			for(int i=a;i<=b;i++) ans=min(ans,i-a+1+(i|b)-b);
			printf("%d\n",ans);
		}
	}
	return 0;
}