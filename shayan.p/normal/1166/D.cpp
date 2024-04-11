// High above the clouds there is a rainbow...

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

ll arr[100],ans[100];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>q;
    while(q--){
	ll a,b,m;cin>>a>>b>>m;
	if(a==b){
	    cout<<1<<" "<<a<<"\n";
	    continue;
	}
	ll A=a;
	for(int lg=0;A<=b;lg++,A*=2){
	    arr[lg]=a-1;
	    ll B=b-A-(1ll<<lg);
	    if(B<0) break;
	    for(int i=lg-1;i>=0;i--){
		ll num=B>>i;
		num=min(num,m-1);
		B-=num<<i, arr[i]=num;
	    }
	    reverse(arr,arr+lg+1);
	    arr[lg+1]=B;
	    
	    if(B>m-1) continue;
	    
	    ans[0]=arr[0]+1;
	    
	    for(int i=1;i<=lg+1;i++){
		ans[i]=2*ans[i-1]+arr[i]-arr[i-1];
	    }
	    
	    cout<<lg+2<<" ";
	    for(int i=0;i<lg+2;i++){
		cout<<ans[i]<<" ";
	    }
	    cout<<"\n";
	    goto Hell;
	}
	cout<<"-1\n";
    Hell:;
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.