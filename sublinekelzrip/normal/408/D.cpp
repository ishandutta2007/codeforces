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
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int d[2010],num[2010];
int main()
{
	int n,n1;
	cin>>n;
	for(n1=1;n1<=n;n1++)
		scanf("%d",&num[n1]);
	for(n1=1;n1<=n;n1++)
		if(num[n1]==n1)
			d[n1]=1;
		else
		{
			d[n1]=1;
			for(int k=num[n1];k<n1;k++)
				d[n1]=(d[n1]+d[k]+1)%1000000007;
		}
	int ans=0;
	for(n1=1;n1<=n;n1++)
		ans=(ans+d[n1]+1)%1000000007;
	cout<<ans;
}