#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,k,i;
		cin>>n>>k;
		vector<ll> s(n+1);
		for (i=1;i<=n;i++) cin>>s[i],s[i]+=s[i-1];
		if (k>n)
		{
			s[n]+=(ll)(k-n)*n;
			k=n;
		}
		ll mx=s[k];
		for (i=k+1;i<=n;i++) mx=max(mx,s[i]-s[i-k]);
		cout<<mx+k*(k-1ll)/2<<'\n';
	}
}