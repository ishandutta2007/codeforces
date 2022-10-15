#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int fst=1;
		for(int i=1;i<=n;i++) if(a[i]==i) fst++; else break;
		for(int i=1;i<=n;i++) 
		{
			if(a[i]==fst)
			{
				reverse(a+fst,a+i+1);
				break;
			}
		}
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}