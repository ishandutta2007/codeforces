#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bool f=false;
	for(int i=1;i<=n;i++)
	{
		if(a[a[a[i]]]==i)
		{
			f=true;
			break;
		}
	}
	if(f) puts("YES"); else puts("NO");
	return 0;
}