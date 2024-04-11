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

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    int mn=55,cnt=0;
    for(int i=0;i<n;i++){
	cin>>a[i];
	mn=min(mn,a[i]);
    }
    for(int i=0;i<n;i++){
	if(mn==a[i]) cnt++;
    }
    if(cnt<=(n/2)) return cout<<"Alice\n",0;
    else return cout<<"Bob\n",0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.