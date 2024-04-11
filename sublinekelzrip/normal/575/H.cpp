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
const int mod=inf+7;
long long jc[2000010],fjc[2000010];
int c(int i,int j)
{
	if(j>i)
		return 0;
	return jc[i]*fjc[j]%mod*fjc[i-j]%mod;
}
int main()
{
	int n,n1;
	cin>>n;
	jc[0]=1;
	for(n1=1;n1<=2*n;n1++)
		jc[n1]=jc[n1-1]*n1%mod;
	fjc[0]=fjc[1]=1;
	for(n1=2;n1<=2*n;n1++)
		fjc[n1]=(mod-fjc[mod%n1]*(mod/n1)%mod)%mod;
	for(n1=2;n1<=2*n;n1++)
		fjc[n1]=fjc[n1-1]*fjc[n1]%mod;
	int ans=1,now=1;
	for(n1=1;n1<=2*n;n1++)
	{
		int p=(now+2ll*mod-c(n1-1,n)*2ll)%mod;
		now=(now+p)%mod;
		ans=(ans+now)%mod;
	//	cout<<p<<' '<<now<<' '<<ans<<endl;
	}
	cout<<ans;
		
	
		
}