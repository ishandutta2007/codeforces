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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

pii p[maxn];
int mm;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	int x,mx=0;cin>>x;
	for(int j=0;j<x;j++){
	    int y;cin>>y;
	    mx=max(mx,y);
	    mm=max(mm,y);
	}
	p[i]={x,mx};
    }
    ll ans=0;
    for(int i=0;i<n;i++){
	ans+=1ll*p[i].F*(mm-p[i].S);
    }
    cout<<ans<<endl;
    return 0;
}