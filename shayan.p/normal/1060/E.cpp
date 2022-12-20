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

int cnt0,cnt1,n;
ll ans;
vector<int>v[maxn];

int dfs(int u,int h=0,int par=-1){
    int SZ=1;
    if(h&1) cnt1++;
    else cnt0++;
    for(int y:v[u]){
	if(y!=par)
	    SZ+=dfs(y,h+1,u);
    }
    ans+=1ll*SZ*(n-SZ);
    return SZ;
}

int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
	int a,b;scanf("%d%d",&a,&b);
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    ans+=1ll*cnt0*cnt1;
    ans/=2;
    printf("%lld\n",ans);
}