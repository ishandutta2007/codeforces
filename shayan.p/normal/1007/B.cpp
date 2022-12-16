// Remember...

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
typedef pair<pll,ll> pl3;
typedef pair<pii,int> pi3;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int cnt[maxn];
ll dp1[maxn], dp2[maxn];

int gc[8], a[3], b[3];

ll f(int m1,int m2,int m3){
    ll tot= 1ll*cnt[ gc[m1] ]*cnt[ gc[m2] ]* cnt[ gc[m3] ];
    ll C=cnt[ gc[ m1 | m2 | m3] ];
    ll B=1ll*cnt[ gc[m1 | m2] ]*cnt[ gc[m3] ] + 1ll*cnt[ gc[m1 | m3] ]*cnt[ gc[m2] ] + 1ll*cnt[ gc[m2 | m3] ]*cnt[ gc[m1] ] - 3ll*C;
    ll A=tot - B -C;
    return A+2*B+6*C;
}

int prm[6][3]={
    {0,1,2},
    {0,2,1},
    {1,0,2},
    {1,2,0},
    {2,0,1},
    {2,1,0}
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i=1;i<maxn;i++){
	for(int j=i;j<maxn;j+=i)
	    cnt[j]++;
    }
    int q; cin>>q;

    while(q--){
	cin>>a[0]>>a[1]>>a[2];
	gc[0]=0;
	for(int msk=1;msk<8;msk++){
	    gc[msk]= __gcd(gc[msk ^ (msk & -msk)], a[__builtin_ctz(msk)]);
	}
	ll ans=0;
	for(int msk=1;msk<(1<<6);msk++){
	    b[0]= b[1]= b[2]= 0;
	    for(int i=0;i<6;i++){
		if(bit(msk,i)){
		    for(int j=0;j<3;j++){
			b[j]|= 1<<prm[i][j];
		    }
		}
	    }
	    ans+=(__builtin_popcount(msk)&1 ? 1 : -1) * f( b[0], b[1], b[2] );
	}
	cout<<ans/6<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")