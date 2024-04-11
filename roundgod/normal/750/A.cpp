#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,k,a[MAXN];
int main()
{
	scanf("%d%d",&n,&k);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		k+=5*i;
		if(k>240) break; else cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}