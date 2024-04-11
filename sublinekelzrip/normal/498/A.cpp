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
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int n;
	cin>>n;
	long long t1,t2,t3,ans=0,n1;
	for(n1=1;n1<=n;n1++)
	{
		scanf("%I64d%I64d%I64d",&t1,&t2,&t3);
		if(t1*a+t2*b+t3<0&&t1*c+t2*d+t3>0)
			ans++;
		if(t1*a+t2*b+t3>0&&t1*c+t2*d+t3<0)
			ans++;
	}
	cout<<ans;
}