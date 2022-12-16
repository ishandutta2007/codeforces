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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn], ans[maxn], arr[maxn];
vector<pii> qu[maxn];

int fn[maxn];

void add(int i,int x){
    for(i+=3; i<maxn; i+=i & -i)
	fn[i]+=x;
}
int ask(int x){
    int ans=0;
    for(int i=17;i>=0;i--){
	if(ans + (1<<i) < maxn && fn[ans + (1<<i)]<x)
	    ans+=1<<i, x-=fn[ans];	
    }
    return ans+1-3;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    int n; cin>>n;

    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    int q; cin>>q;
    for(int i=0;i<q;i++){
	int a,b; cin>>a>>b;
	qu[a-1].PB({b,i});
    }
    for(int i=0;i<n;i++){
	arr[i]=i;
    }
    sort(arr,arr+n, [](int x,int y){ return (a[x]==a[y] ? x<y : a[x]>a[y]); });
    for(int i=0;i<n;i++){
	add(arr[i],1);
	for(pii p:qu[i]){
	    ans[p.S]= a[ask(p.F)];
	}
    }
    for(int i=0;i<q;i++){
	cout<<ans[i]<<"\n";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")