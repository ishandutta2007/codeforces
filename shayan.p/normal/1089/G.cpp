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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int a[7];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;

    while(q--){
	int x, tot=0; cin>>x;
	for(int i=0;i<7;i++)
	    cin>>a[i], tot+= a[i];
	int ans=0;
	if(x%tot==0){
	    ans+=(x/tot)*7 -7;
	    x=tot;
	}
	else{
	    ans+=(x/tot)*7;
	    x%=tot;
	}
	int an=7;
	for(int i=0;i<7;i++){
	    int num=0;
	    for(int cnt=0;cnt<7;cnt++){
		num+= a[(i + cnt)%7];
		if(num==x)
		    an=min(an, cnt+1);
	    }
	}
	ans+= an;
	cout<<ans<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")