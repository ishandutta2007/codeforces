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
const ll inf=2e18;

ll ans[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    ll A=0,B=inf;
    for(int i=0;i<n/2;i++){
	ll x;cin>>x;
	ans[i]=max(A,x-B);
	ans[n-1-i]=x-ans[i];
	A=ans[i];B=ans[n-1-i];
    }
    for(int i=0;i<n;i++){
	cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}