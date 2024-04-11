// Phoenix

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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,ans=0;cin>>n>>k;
    for(int i=0;i<n;i++){
	int x;cin>>x;
	if(vec.empty() || vec.back()!=x)
	    vec.PB(x);
	else
	    ans=max(ans,sz(vec)),vec.clear(),vec.PB(x);
    }
    ans=max(ans,sz(vec));
    cout<<ans<<endl;
    return 0;
}