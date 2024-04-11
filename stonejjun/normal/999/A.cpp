#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<deque>
#define LL long long int
#define MOD 1000000007
using namespace std;
int main()
{
    int i,j,k,n,m,a,b,c,arr[150],ans=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
    	scanf("%d",&arr[i]);
	}
	j=1;
	while(arr[j]<=m)
	{
		ans++;
		j++;
	}
	k=n;
	while(arr[k]<=m)
	{
		ans++;
		k--;
	}
	if(ans>n) ans=n;
	printf("%d\n",ans);
    return 0;
}