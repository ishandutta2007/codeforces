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

const int maxn=1010,mod=1e9+7;
const ll inf=1e18;

bitset<maxn> ans[maxn];
set<pii> st;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    st.insert({0,n});
    for(int i=0;i<n;i++){
	int x; cin>>x;
	auto it=st.begin();
	while(it!=st.end() && (it->S)==(it->F))
	    it++;
	int L=-1, R=-1;
	if(it!=st.end()){
	    int l=it->F;
	    R=it->S, L=l;
	    while(x>0 && l!=R){
		ans[l][i]=1;
		l++, x--;
	    }
	    st.erase(it);
	    st.insert({l,R});
	    st.insert({L,l-1});	 
	}
	for(int j=0;j<=n;j++){
	    if(L<=j && j<=R) continue;
	    if(x>0) x--, ans[j][i]=1;
	}
    }
    cout<<n+1<<"\n";
    for(int i=0;i<=n;i++){
	for(int j=0;j<n;j++)
	    cout<<ans[i][j];
	cout<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")