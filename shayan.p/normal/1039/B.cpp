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

ll n,k;

bool ask(ll l,ll r){
    cout<<l<<" "<<r<<endl;
    string s;cin>>s;
    if(s=="Yes" && l==r)
	exit(0);
    return (s=="Yes");
}

ll f(ll x){
    if(0<x && x<=n)return x;
    if(x<=0)return 1;
    return n;
}

int main(){
    srand(100);
    cin>>n>>k;
    ll l=1,r=n;
    while(true){
	if((r-l)>60){
	    ll mid=(l+r)/2;
	    if(ask(f(mid),f(r))){
		l=f(mid-k);
		r=f(r+k);
	    }
	    else{
		l=f(l-k);
		r=f(mid+k);
	    }
	}
	else{
	    ll SZ=r-l+1,pos=l+(rand()%SZ);
	    l=f(l-k);
	    r=f(r+k);
	    ask(pos,pos);
	}
    }
}