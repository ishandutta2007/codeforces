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
typedef pair<pii,int> pi3;

const int maxn=5e4+10,mod=1e9+7;
const ll inf=1e18;

pi3 p[maxn];
int arr[maxn];
bool is[maxn];

vector<int> vec, vec1, vec2;

bool cmp(int a,int b){
    return p[a]<p[b];
}

void solve(){
    vec2.clear();
    for(int i=0;i<sz(vec);i++){
	vec2.PB(vec[i]);
	if(sz(vec2)>1 && p[ vec2[ sz(vec2)-2 ] ].F == p[ vec2[ sz(vec2)-1 ] ].F){
	    cout<<vec2[sz(vec2)-2]+1<<" "<<vec2[sz(vec2)-1]+1<<"\n";
	    vec2.pop_back();
	    vec2.pop_back();
	}
    }
    while(sz(vec2)>1){
	cout<<vec2[sz(vec2)-2]+1<<" "<<vec2[sz(vec2)-1]+1<<"\n";
	vec2.pop_back();
	vec2.pop_back();	
    }
    vec=vec2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;

    for(int i=0;i<n;i++){
	cin>>p[i].F.F>>p[i].F.S>>p[i].S;
	arr[i]=i;
    }
    sort(arr,arr+n,cmp);    
    for(int i=0;i<n;i++){
	vec.PB(arr[i]);
	if(i==n-1 || p[ arr[i] ].F.F != p[ arr[i+1] ].F.F){
	    solve();
	    if(sz(vec)){
		vec1.PB(vec[0]);
		vec.clear();
	    }
	}
    }
    for(int i=0;i<sz(vec1);i+=2){
	cout<<vec1[i]+1<<" "<<vec1[i+1]+1<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")