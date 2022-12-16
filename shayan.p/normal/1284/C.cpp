// They can't break me, as long as I know who I am...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 3e5 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

int fac[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,m; cin>>n>>m;

    fac[0] = 1;
    for(int i = 1; i < maxn; i++)
	fac[i] = 1ll* i *fac[i-1] %m;
    int ans = 0;
    for(int i = 1; i <=n; i++){
	ans = (1ll * ans + 1ll * (n-i+1) * (n-i+1) %m * fac[i] %m * fac[n-i]) %m;
    }
    return cout<<ans<<endl,0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")