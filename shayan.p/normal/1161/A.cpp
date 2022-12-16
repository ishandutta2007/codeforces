// Faster!

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

int lst[maxn],fr[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(lst,-1,sizeof lst);
    memset(fr,-1,sizeof fr);
    int n,k;cin>>n>>k;
    for(int i=0;i<k;i++){
	int x;cin>>x;
	if(fr[x]==-1) fr[x]=i;
	lst[x]=i;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
	ans+= lst[i]==-1;
	ans+= i>1 && (lst[i-1]<fr[i] || lst[i]==-1);
	ans+= i<n && (lst[i+1]<fr[i] || lst[i]==-1);
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.