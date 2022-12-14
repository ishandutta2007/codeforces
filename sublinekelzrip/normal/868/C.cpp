#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int hv[30],num[100010];
int main()
{
	int ans=0;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<k;j++)
		{
			int t1;
			scanf("%d",&t1);
			num[i]|=t1*(1<<j);
		}
		hv[num[i]]=1;
		for(int x=0;x<(1<<k);x++)
			if(hv[x]&&((x&num[i])==0))
				ans=1;
	}
	if(ans)
		cout<<"YES";
	else
		cout<<"NO";
			
}