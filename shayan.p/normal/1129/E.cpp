// Remember...

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

int SZ[maxn], n;
bool mark[maxn];
vector<pii> v, ans;

void dfs(int u){
    mark[u]=1;
    int num=1;
    while(num<SZ[u]){
	v.clear();
	for(int i=1;i<=n;i++)
	    if(mark[i]==0)
		v.PB({SZ[i],i});
	sort(v.begin(), v.end());
	int l=-1,r=sz(v)-1;
	while(r-l>1){
	    int mid=(l+r)>>1;
	    cout<<1<<endl<<1<<endl;
	    cout<<mid+1<<endl;
	    for(int i=0;i<=mid;i++)
		cout<<v[i].S<<" ";
	    cout<<endl;
	    cout<<u<<endl;
	    int x; cin>>x;
	    if(x < SZ[u]-num)
		l=mid;
	    else
		r=mid;
	}
	num+=v[r].F;
	ans.PB({u,v[r].S});
	dfs(v[r].S);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin>>n;

    if(n==2){
	cout<<"ANSWER"<<endl;
	cout<<1<<" "<<2<<endl;
	return 0;
    }
    
    SZ[1]=n;
    for(int i=2;i<=n;i++){
	cout<<1<<endl<<1<<endl;
	cout<<n-1<<endl;
	for(int j=2;j<=n;j++)
	    cout<<j<<" ";
	cout<<endl;
	cout<<i<<endl;
	cin>>SZ[i];
    }
    dfs(1);
    cout<<"ANSWER"<<endl;
    for(pii p:ans){
	cout<<p.F<<" "<<p.S<<endl;
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")