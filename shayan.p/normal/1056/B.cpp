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

const int maxn=1010,mod=1e9+7;
const ll inf=1e18;

ll cnt[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
	int rem=1ll*i*i %m;
	cnt[rem]+=(n-i+m)/m -(i==0);
    }
    ll ans=0;
    for(int i=0;i<m;i++){
	ans+=1ll*cnt[i]*cnt[(m-i)%m];
    }
    cout<<ans<<endl;
    return 0;
}