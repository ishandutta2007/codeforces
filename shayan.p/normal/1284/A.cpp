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

const int maxn = 1e5 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

string a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,m; cin>>n>>m;
    for(int i = 0; i < n; i++)
	cin>>a[i];
    for(int i = 0; i < m; i++)
	cin>>b[i];
    int q; cin>>q;
    while(q--){
	ll x; cin>>x;
	--x;
	cout<<a[x % n] + b[x % m]<<"\n";
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")