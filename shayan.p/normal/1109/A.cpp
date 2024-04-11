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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn];
map<int,int>mp[2];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    mp[0][0]=1;
    ll ans=0;
    for(int i=1;i<=n;i++){
	cin>>a[i];
	a[i]^=a[i-1];
	ans+=mp[i&1][a[i]];
	mp[i&1][a[i]]++;
    }
    return cout<<ans<<endl,0;
}