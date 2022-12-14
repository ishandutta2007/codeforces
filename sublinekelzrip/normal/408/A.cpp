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
int num[105],ans[105];
int main()
{
	int n,n1;
	cin>>n;
	for(n1=1;n1<=n;n1++)
		scanf("%d",&num[n1]);
	for(n1=1;n1<=n;n1++)
	{
		ans[n1]=num[n1]*15;
		for(int k=1;k<=num[n1];k++)
		{
			int t;
			scanf("%d",&t);
			ans[n1]+=5*t;
		}
	}
	sort(ans+1,ans+n+1);
	cout<<ans[1];
}