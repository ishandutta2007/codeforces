//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll n, m, k;

ll qpow(ll a, ll b)
{
    ll ret = 1;
    for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ret = ret * a % mod;
    return ret;
}

int main()
{
	cin>>n>>m>>k;
	if(((n + m) & 1) && (k == -1)) cout<<0<<endl;
	else cout<<qpow(qpow(2, n-1), m-1)<<endl;
	return 0;
}