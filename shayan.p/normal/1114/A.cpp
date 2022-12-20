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
    int x,y,z;cin>>x>>y>>z;
    int a,b,c;cin>>a>>b>>c;
    int flw=min(a+b-x,y+z);
    if(a-x>=0 && flw-y>=0 && flw-y>=z-c) cout<<"YES\n";
    else cout<<"NO\n";
}