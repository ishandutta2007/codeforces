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

ll solve(ll num,bool b){
    if(num==0)return 0;
    if(!b){
	if(num==1)return 1;
	if(num==2)return 2;
	if(num%2)return 0;
	return 1;
    }
    else{
	if(num==1)return 1;
	if(num==2)return 0;
	if(num==3)return 1;
	if(num==4)return 2;
	if(num%2)return 0;
	if(solve(num/2,b)==1)return 2;
	return 1;
    }
}

int main(){
    ll n,k;cin>>n>>k;
    ll ans=0;
    REP(i,n){
	ll x;cin>>x;
	ans^=solve(x,k%2);
    }
    cout<<(ans==0?"Nicky":"Kevin");
}