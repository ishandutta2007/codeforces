// Can U hack it?

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

int f(ll x){
    int ans=0;
    while(x>0){
	ans+=(x%10);
	x/=10;
    }
    return ans;
}

int main(){
    ll n,ans=0;cin>>n;
    for(int msk=0;msk<(1<<13);msk++){
	ll tn=1,A=0,B=0;
	for(int i=0;i<13;i++){
	    if(bit(msk,i))
		A+=tn*9;
	    tn*=10;
	}
	B=n-A;
	if(B<0)continue;
	ans=max(ans,ll(f(A)+f(B)));
    }
    cout<<ans;
}