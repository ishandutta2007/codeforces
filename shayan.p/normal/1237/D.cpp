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

int a[maxn], aft[maxn], arr[maxn], nxt[maxn], ans[maxn];
set<int> st;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    int N=2*n;
    for(int i=0;i<n;i++){
	cin>>a[i];
	arr[i]=i;
    }
    for(int i=n;i<N;i++){
	a[i]= a[i-n];
    }
    for(int i=N-1;i>=0;i--){
	aft[i]= i+1;
	while( aft[i]<N && a[ aft[i] ] <= a[i] ) aft[i]= aft[ aft[i] ];	
    }
    sort(arr,arr+n, [](int i,int j){ return a[i]<a[j]; } );
    int pt=0;
    for(int i=0;i<n;i++){
	while(pt<i && 2*a[arr[pt]]<a[arr[i]]){
	    st.insert(arr[pt]);
	    st.insert(n+arr[pt]);
	    pt++;
	}
	auto it=st.lower_bound(arr[i]);
	if(it!=st.end() && (*it)<aft[arr[i]]){
	    nxt[ arr[i] ]=-(*it);
	}
	else{
	    nxt[ arr[i] ]=aft[ arr[i] ]%n;
	    if(aft[arr[i]] == 2*n) nxt[ arr[i] ]=2*n;
	}
    }
    for(int i=n-1;i>=0;i--){
	if(nxt[arr[i]]==2*n){
	    ans[ arr[i] ]=-1;
	}
	else if(nxt[arr[i]]<0){
	    ans[arr[i]]= (-nxt[arr[i]] - arr[i] + n) %n;
	}
	else{
	    if(ans[ nxt[arr[i]] ]==-1) ans[arr[i]]=-1;
	    else ans[arr[i]]= ((nxt[arr[i]]-arr[i]+n)%n) + ans[ nxt[ arr[i] ] ];
	}
    }
    for(int i=0;i<n;i++){
	cout<<ans[i]<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")