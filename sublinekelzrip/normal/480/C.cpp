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
long long qz[5010],dp[5010];
const int mod=1000000007;
int main()
{
	int n,a,b,k,n1;
	cin>>n>>a>>b>>k;
	for(n1=1;n1<=n;n1++)
		if(n1>=a)
			qz[n1]=1;
		else
			qz[n1]=0;
	dp[a]=1;
	for(int k1=1;k1<=k;k1++)
	{
		for(n1=1;n1<=n;n1++)
		{
			int l,r;
			if(n1==b)
				continue;
			if(n1<b)
			{
				l=1;
				r=n1+(b-n1-1)/2;
			}
			else
			{
				r=n;
				l=n1-(n1-b-1)/2;
			}
		//	cout<<l<<' '<<r<<endl;
			dp[n1]=(qz[r]-qz[l-1]+mod-dp[n1]+mod)%mod;
		}
		for(n1=1;n1<=n;n1++)
			qz[n1]=(dp[n1]+qz[n1-1])%mod;
	}
	cout<<qz[n]<<endl;
}