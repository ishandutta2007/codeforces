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

multiset<int> st;
int ans=0;

void f(int big,int small){
    int cnt=0;
    while(sz(st) && (*st.rbegin())>big){
	cnt++;
	st.erase( st.find( *st.rbegin() ) );
    }
    ans+= cnt;
    auto it= st.upper_bound(small);
    while(sz(st) && cnt && it!=st.begin()){
	cnt--;
	st.erase( prev(it) );
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    int a,b,c; cin>>a>>b>>c;
    if(a>b) swap(a,b);
    if(a>c) swap(a,c);
    if(b>c) swap(b,c);
    for(int i=0;i<n;i++){
	int x; cin>>x;
	st.insert(x);
    }
    if((*st.rbegin()) > a+b+c) return cout<<-1<<endl,0;
    
    f(b+c,-1);
    f(a+c,a);

    if(a+b>=c){
	f(a+b,b);
	f(c,c);	
    }
    else{
	f(c,b);
    }
    int extra=n, A=0, B=0, AB=0, now=0;
    if(sz(st)==0) extra=0;
    for(auto x:st){
	if(x<=a) A++;
	else if(x<=b) B++;
	else if(x<=a+b) AB++;
	else break;
	now++;
	extra=min( extra, max( sz(st)-now, AB + B + max(0,(A-B+1)/2) ) );
    }
    ans+= extra;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")