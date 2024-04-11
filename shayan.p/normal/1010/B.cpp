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

const ll maxn=40;

bool p[maxn];

bool ask(ll x){
    cout<<x<<endl;
    cin>>x;
    if(x==0){
	exit(0);
    }
    return (x==(-1));
}

int main(){
    ll m,n;cin>>m>>n;
    REP(i,n){
	p[i]=ask(1);
    }
    ll l=1,r=m;
    REP(i,30){
	ll mid=(l+r)/2;
	if(ask(mid)^p[i%n])
	    r=mid-1;
	else
	    l=mid+1;
    }    
}