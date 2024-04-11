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

const int maxn=1e6+1000,mod=1e9+7;
const ll inf=1e18;

int cnt[maxn];

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
	int x;scanf("%d",&x);
	cnt[x]++;
    }
    int ans=0;
    for(int i=0;i<(maxn-1);i++){
	if(cnt[i]&1)ans++;
	cnt[i+1]+=cnt[i]/2;
    }
    printf("%d\n",ans);
}