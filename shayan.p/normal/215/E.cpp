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

vector<int>vec;
ll tw[62];

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    tw[0]=1;
    for(int i=1;i<62;i++)
	tw[i]=2*tw[i-1];
    
    ll l,r,ans=0;scanf("%lld%lld",&l,&r);
    for(int ln=1;ln<=60;ln++){
	vec.clear();
	for(int i=1;i<ln;i++)
	    if(ln%i==0)
		vec.PB(i);
	for(int msk=1;msk<(1<<sz(vec));msk++){
	    int num=0;
	    for(int i=0;i<sz(vec);i++)
		if(bit(msk,i))
		    num=gcd(num,vec[i]);
	    ll x=0;
	    for(int i=0;i<ln;i+=num)
		x+=tw[i];
	    ll R=min(tw[num]-1,r/x),L=max(tw[num-1],(l+x-1)/x);
	    if(L>=tw[num] || R<tw[num-1])continue;
	    ans+=(__builtin_popcount(msk)&1?1:-1)*max(ll(0),R-L+1);
	}
    }
    printf("%lld\n",ans);
}