#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Base
{
	#define type ll
	#define mx 36
	type d[mx+1];
	Base()
	{
        for (int i=0;i<=mx;i++)
            d[i]=0;
	}
	bool insert(type x)
	{
		int i;
		for(i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			if(!d[i])
			{
				d[i]=x;
				break;
			}
			x^=d[i];
		}
		return x>0;
	}
};
pair<ll,ll> split(ll x, int bits){
    return { x>>bits, x&((1<<bits)-1) };
}
vector<ll> Generate(vector<ll> x){
    int n = x.size();
    vector<ll> vec;
    for (int mask=0;mask<(1<<n);mask++){
        ll ret=0;
        for (int i=0;i<x.size();i++){
            if ((1<<i)&mask) ret^=x[i];
        }
        vec.push_back(ret);
    }
    return vec;
}
ll n, m;
int cnt[1000];
int ret[1000];
ll a[1000000];
int mod = 998244353;
int num[1<<9][1<<9][36];
int main() {
    scanf("%d%d", &n, &m);
    Base gauss;
    int extra=1;
    for (int i=0;i<1000;i++)
        cnt[i] = __builtin_popcount(i);
    for (int i=0;i<n;i++) {
        scanf("%lld", &a[i]);
        if (!gauss.insert(a[i])) extra=(extra*2)%mod;
    }
    vector<ll> v1,v2;
    for (int i=0;i<36;i++){
        if (gauss.d[i]>0){
            if (i<=17) v1.push_back(gauss.d[i]);
            else v2.push_back(gauss.d[i]);
        }
    }
    vector<ll> small = Generate(v1);
    vector<ll> large = Generate(v2);
    int lim = (1<<9);
    for (auto x:small){
        auto [L,R] = split(x, 9);
        for (int i=0;i<lim;i++)
            num[i][R][cnt[L^i]]++;
    }
    for (auto x:large){
        auto [L1,R1] = split(x, 18);
        auto [L,R] = split(R1, 9);
        int cntL1 = __builtin_popcount(L1);
        for (int i=0;i<lim;i++) {
            for (int j=0;j<10;j++) {
                ret[cnt[R^i]+j+cntL1]+=num[L][i][j];
                if (ret[cnt[R^i]+j+cntL1]>=mod)
                    ret[cnt[R^i]+j+cntL1]-=mod;
            }
        }
        ret[0]=1;
    }
    for (int i=0;i<=m;i++)
        printf("%lld ", (ret[i]*1LL*extra)%mod);
}