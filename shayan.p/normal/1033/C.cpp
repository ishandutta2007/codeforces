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

int pos[maxn],a[maxn];
bool ans[maxn],dp[maxn];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	pos[a[i]]=i;
    }
    for(int i=n;i>=1;i--){
	for(int j=i;j<=n;j+=i){
	    if((pos[i]-j)>0 && a[pos[i]-j]>i) dp[i]|=!dp[a[pos[i]-j]];
	    if((pos[i]+j)<=n && a[pos[i]+j]>i) dp[i]|=!dp[a[pos[i]+j]];
	}
	ans[pos[i]]=dp[i];
    }
    for(int i=1;i<=n;i++){
	if(ans[i])
	    printf("A");
	else
	    printf("B");
    }
    printf("\n");
}