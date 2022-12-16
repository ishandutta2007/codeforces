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
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll solve(ll n){
    set<ll>s;
    s.clear();
    FOR(i,0,n){
	FOR(j,i,n){
	    FOR(k,j,n){
		s.insert(i*4 + (j-i)*9 + (k-j)*49 );
	    }
	}
    }
    return sz(s);
}

int main(){
    ll n;cin>>n;
    if(n<=50)
	cout<<solve(n);
    else
	cout<<49*(n-30)+solve(30);
}