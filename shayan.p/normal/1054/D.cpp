// Can U hack it?

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

map<int,int>mp;
ll ans;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    int bf=0,NM=(1<<k)-1;
    mp[0]++;
    for(int i=1;i<=n;i++){
	int x;scanf("%d",&x);
	bf^=x;
	if(bit(bf,k-1)) bf^=NM;
	mp[bf]++;
    }
    ans=(1ll*n*(n+1))/2;
    for(auto p:mp){
	ll A=p.S/2,B=p.S-A;
	ans-=(1ll*A*(A-1)/2);
	ans-=(1ll*B*(B-1)/2);
    }
    printf("%lld\n",ans);
    return 0;
}