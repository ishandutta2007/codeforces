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
int num[1010];
int main()
{
	int n,m,ans=0,n1,m1;
	cin>>n>>m;
	for(n1=1;n1<=n;n1++)
		cin>>num[n1];
	for(m1=1;m1<=m;m1++)
	{
		int t1,t2;
		cin>>t1>>t2;
		ans+=min(num[t1],num[t2]);
	}
	cout<<ans<<endl;
}