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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn],b[maxn];
ll ans;

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
	scanf("%d%d",&a[i],&b[i]);
	ans+=a[i]+b[i];
    }
    ans+=n;
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++){
	ans-=min(a[i],b[i]);
    }
    printf("%lld\n",ans);
}