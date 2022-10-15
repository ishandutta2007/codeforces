#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m;
int a[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	if(n>27)
	{
		printf("%d\n",m);
		return 0;
	}
	else
	{
		int s=1;
		for(int i=0;i<n;i++)
			s=s*2;
		printf("%d\n",m%s);
		return 0;
	}
	return 0;
}