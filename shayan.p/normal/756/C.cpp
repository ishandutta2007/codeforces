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
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e5+10;
const ll mod=1e9+7;
const ll tw=131072;
    
ll a[maxn];

ll mx[2*tw],sm[2*tw];

void add(ll ind,ll x){
    ind+=tw;
    sm[ind]=mx[ind]=x;
    while(ind>1){
	ind/=2;
	sm[ind]=sm[2*ind]+sm[2*ind+1];
	mx[ind]=max(mx[2*ind+1],sm[2*ind+1]+mx[2*ind]);
    }
}
ll ask(ll s){
    ll f=tw;
    s+=tw+1;
    ll num=0;
    while(true){
	if(f>=s)return -1;
	if(s%2){
	    if((num+mx[--s])>0)break;
	    num+=sm[s];
	}
	f/=2;
	s/=2;
    }
    while(s<tw){
	if((num+mx[2*s+1])>0){
	    s=2*s+1;
	}
	else{
	    num+=sm[2*s+1];
	    s=2*s;
	}   
    }
    return s-tw;
}

int main(){
    ll n;cin>>n;
    REP(i,n){
	ll p,t;cin>>p>>t;
	if(t==0){
	    add(p,-1);
	}
	else{
	    cin>>a[p];
	    add(p,1);
	}
	ll pos=ask(n);
	cout<<(pos==-1?-1:a[pos])<<endl;
    }
}