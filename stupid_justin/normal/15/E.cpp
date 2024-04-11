
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+9;
int n,sum=2,cnt1=4,cnt2=1;
signed main()
{
	cin>>n;
	for (int i=3;i<=n;i+=2) 
    {
        cnt1=cnt1*cnt2%mod;
        cnt2=(2*cnt2+3)%mod;
        sum+=cnt1;sum%=mod;
    }
    cout<<(sum*sum+1)*2%mod;
}