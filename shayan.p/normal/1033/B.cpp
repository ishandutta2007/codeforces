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

bool prime(ll x){
    for(ll i=2;(i*i)<=x;i++){
	if(x%i==0)return 0;
    }
    return 1;
}

int main(){
    int q;scanf("%d",&q);
    while(q--){
	ll a,b;scanf("%lld%lld",&a,&b);
	if(abs(a-b)==1 && prime(a+b))
	    printf("YES\n");
	else
	    printf("NO\n");
    }
}