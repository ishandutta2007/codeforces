// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll a[maxn],b[maxn],pos;
vector<ll>ad[maxn],rm[maxn];
ll fr[maxn],ls[maxn];
set<ll>st;

int main(){
    ll n,q;cin>>n>>q;
    FOR(i,1,n){
	cin>>a[i];
    }
    pos=-1;
    FOR(i,1,q){
	fr[i]=ls[i]=-1;
    }
    FOR(i,1,n){
	ls[a[i]]=i;
    }
    FORD(i,n,1){
	fr[a[i]]=i;
    }
    FOR(i,1,n){
	if(a[i]==0){
	    pos=i;
	}
    }
    
    ad[1].PB(1);
    FOR(i,2,q){
	if(fr[i]!=(-1)){
	    ad[fr[i]].PB(i);
	    rm[ls[i]].PB(i);
	}
    }
    FOR(i,1,n){
	for(ll x:ad[i]){
	    st.insert(x);
	}
	b[i]=(*st.rbegin());
	for(ll x:rm[i]){
	    st.erase(x);
	}
    }
    if(pos==(-1)){
	bool is=0;
	FOR(i,1,n){
	    if(a[i]==q){
		is=1;
	    }
	}
	if(!is){
	    cout<<"NO";
	    return 0;
	}
    }
    else if(fr[q]==(-1)){
	b[pos]=q;
    }
    
    FOR(i,1,n){
	if(a[i]!=0 && a[i]!=b[i]){
	    cout<<"NO";
	    return 0;
	}
    }
    cout<<"YES\n";
    FOR(i,1,n){
	cout<<b[i]<<" ";
    }
}