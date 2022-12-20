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

ll N,n;

ll ask(ll x){
    while(x>N)
	x-=n;
    cout<<"? "<<x<<endl;
    cin>>x;
    return x;
}

void tell(ll x){
    while(x>N)
	x-=n;
    cout<<"! "<<x<<endl;
    exit(0);
}

int main(){
    cin>>N;
    n=N/2;
    ll A=ask(1)-ask(n+1),B=-A,l=1,r=n;
    if(A==0){
	tell(1);
    }
    if(A%2){
	tell(-1);
    }
    while(l<(r-1)){
	ll mid=(l+r)/2;
	ll x=ask(mid)-ask(mid+n);
	if(x==0){
	    tell(mid);
	}
	if((x<0) xor (A<0)){
	    r=mid;
	    B=x;
	}
	else{
	    l=mid;
	    A=x;
	}
    }
    if((ask(l)-ask(l+n))==0)
	tell(l);
    if((ask(r)-ask(r+n))==0)
	tell(r);
    tell(-1);
}