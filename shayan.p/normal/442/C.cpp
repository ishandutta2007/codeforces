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

const int maxn=5e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int> st, v1, v2;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    ll ans=0;

    st.PB(0);
    for(int i=0;i<n;i++){
	int x; cin>>x;
	while(sz(st)>1 && st[sz(st)-2]>=st.back() && st.back()<=x) st.pop_back(),  ans+=min(x, st.back());
	st.PB(x);
    }
    st.PB(0);
    int pos=0;
    for(int i=0;i<sz(st);i++)
	if(st[pos]<=st[i]) pos=i;
    for(int i=0;i<=pos;i++)
	v1.PB(st[i]);
    for(int i=sz(st)-1;i>pos;i--)
	v2.PB(st[i]);
    int mx= st[pos], cnt=0;
    while(v1.back()==mx) v1.pop_back(), cnt++;

    while(sz(v1)>1 || sz(v2)>1){
	mx=max( v1.back(), v2.back() );
	while(v1.back()==mx) v1.pop_back(), cnt++;
	while(v2.back()==mx) v2.pop_back(), cnt++;
	ans+= cnt<2 ? 0 : 1ll*(cnt-2)*mx;
	cnt=min(cnt,2);
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")