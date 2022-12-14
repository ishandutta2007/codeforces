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
const int mod=1000000007;
int main()
{
	long long n,t,ans=0;
	cin>>t>>n;
	for(int n1=1;n1<n;n1++)
	{
		long long i=n1*(long long)n+n1%mod,j=n1*(long long)n%mod*(long long)t+n1%mod;
		ans=(ans+(i+j)%mod*(long long)t)%mod;
	}
	if(ans%2==0)
		ans/=2;
	else
		ans=(ans+mod)/2;
	cout<<ans;
}