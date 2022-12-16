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

int pr[maxn], cnt[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i=2;i<maxn;i++){
	if(pr[i]==0){
	    for(int j=i;j<maxn;j+=i)
		pr[j]=i;
	}
    }
    
    int n,k; cin>>n>>k;
    ll ans=0;
    for(int i=0;i<n;i++){
	int x; cin>>x;
	int y=1, z=1;
	while(x>1){
	    int p=pr[x], cnt=0;
	    while(x%p==0) x/=p, cnt++;
	    cnt%=k;

	    for(int j=0;j<cnt;j++)
		y*=p;
	    if(z!=-1){
		ll num=z;
		for(int j=0;j<(k-cnt)%k;j++){
		    num*=p;
		    if(num>=maxn){
			num=-1;
			break;
		    }
		}
		z=num;
	    }
	}
	if(z!=-1) ans+= cnt[z];
	cnt[y]++;
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")