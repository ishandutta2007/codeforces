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
typedef long double ld;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int dg[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,s;cin>>n>>s;
    for(int i=0;i<n-1;i++){
	int a,b;cin>>a>>b;
	dg[a]++;dg[b]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
	if(dg[i]==1)
	    cnt++;
    }
    return cout<<setprecision(10)<<fixed<<(ld(2*s)/ld(cnt))<<endl,0;
}