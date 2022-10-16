#include<bits/stdc++.h>
using namespace std;
const int N=2e6+9 ;
typedef long long ll;
const ll mod=1e9+7;
ll a[N],f[N],t,x,n;
int main() 
{
	cin>>t;
	for(int i=1;i<=t;i++)
    {
		scanf("%lld",&a[i]);
		n=max(n,a[i]);
	}
	f[0]=f[1]=f[2]=0;
    f[3]=4;
	for(int i=4;i<=n;i++)
	{
		f[i]=(f[i-1]+2*f[i-2]%mod)%mod;
		if(i%3==0)
		    f[i]=(f[i]+4)%mod;
	}
	for(int i=1;i<=t;i++)
	    printf("%lld\n",f[a[i]]);
    return 0;
}