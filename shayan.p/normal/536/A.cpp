// Wanna Hack? GL...

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
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll a,B;int q;cin>>a>>B>>q;
    while(q--){
	ll l,t,m;cin>>l>>t>>m;
	ll A=a+(--l)*B;
	ll R=(t-A)/B,L=0,Ans=-l-2;
	while(L<=R){
	    ll mid=(L+R)>>1;
	    ll sm=((mid*(mid+1))/2)*B+A*(mid+1);
	    if(sm<=t*m) Ans=mid,L=mid+1;
	    else        R=mid-1;
	}
	cout<<Ans+l+1<<"\n";
    }
    return 0;
}