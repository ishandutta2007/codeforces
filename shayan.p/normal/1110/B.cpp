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

int a[maxn];
vector<int>vec;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    int ans=n;
    for(int i=1;i<n;i++){
	vec.PB(a[i]-a[i-1]-1);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<n-k;i++){
	ans+=vec[i];
    }
    return cout<<ans<<endl,0;
}