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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    int p1=1, p2=1;

    for(int p=2;p*p<=n;p++){
	if(n%p==0){
	    p2=n, p1=1;
	    while(p2%p==0)
		p1*=p, p2/=p;
	    if(p1>p2) swap(p1, p2);
	    break;
	}
    }
    if(p1==1) return cout<<"NO\n",0;
    int k=1, num=p2 % p1;
    while(num!=p1-1){
	k++;
	num+= p2;
	num%=p1;
    }
    cout<<"YES\n";
    cout<<2<<endl;
    cout<<k<<" "<<p1<<"\n";
    cout<<((n-1-(k*p2))/p1)<<" "<<p2<<"\n";
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")